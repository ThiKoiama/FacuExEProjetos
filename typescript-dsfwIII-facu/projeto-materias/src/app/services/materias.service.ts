import { Injectable } from '@angular/core';

import { AngularFirestore } from '@angular/fire/compat/firestore';
import { Observable } from 'rxjs';
import { Materia } from '../interfaces/Materia';


@Injectable({
  providedIn: 'root'
})

export class MateriasService {

  constructor(private dataBaseStore: AngularFirestore) { }

  getAll() {
    return this.dataBaseStore.collection('materias', materia => materia.orderBy('name')).valueChanges({idFiled: 'firebaseId'}) as Observable<any[]>;
  }

  create(materia: Materia) {
    return this.dataBaseStore.collection('materias').add(materia);
  }

  update(materiaId: string, materia: Materia) {
    return this.dataBaseStore.collection('materias').doc(materiaId).update(materia);
  }

  delete(materiaId: string) {
    return this.dataBaseStore.collection('materias').doc(materiaId).delete();
  }
}
