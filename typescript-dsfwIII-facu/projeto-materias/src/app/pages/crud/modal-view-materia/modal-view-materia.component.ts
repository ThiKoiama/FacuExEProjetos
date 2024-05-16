import { Component, Inject } from '@angular/core';
import { Materia } from '../../../interfaces/Materia';
import { MAT_DIALOG_DATA, MatDialogRef } from '@angular/material/dialog';

@Component({
  selector: 'app-modal-view-materia',
  templateUrl: './modal-view-materia.component.html',
  styleUrl: './modal-view-materia.component.scss'
})
export class ModalViewMateriaComponent {
  materiaData: Materia;


  constructor(public dialogRef: MatDialogRef<ModalViewMateriaComponent>, @Inject(MAT_DIALOG_DATA) public data: any) { 
    console.log('Data recebida', data);
    this.materiaData = data;
  }

  closeModal() { this.dialogRef.close(); }
}
