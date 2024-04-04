import { Component, Input } from '@angular/core';

@Component({
  selector: 'app-button',
  templateUrl: './button.component.html',
  styleUrl: './button.component.scss'
})
export class ButtonComponent {
 @Input() textButton: string;

 @Input() size: string = 'auto';

 contador: number = 0;

//  constructor() {
//   console.log('Componente construído');
// }

// ngOnChanges() {
//   console.log('componente changes');
// }

// ngOnInit() {
//   console.log('componente inicializado');
// }

// ngDoCheck() {
//   console.log('componente check');
// }

// ngAfterViewIniit() {
//   console.log('componente view inicializada');
// }

// ngOnDestroy() {
//   console.log('destruido');
// }



  aoClicar() {
    console.log('aoClicar');
    this.contador++;
  }
}
