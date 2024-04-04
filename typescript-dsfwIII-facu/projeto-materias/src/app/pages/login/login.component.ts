import { Component } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrl: './login.component.scss'
})
export class LoginComponent {
  userName: string = '';

  // adicionar o router para navegar entre as páginas > ir para home
  constructor(private router: Router) {

  }

  login() {
    sessionStorage.setItem('user', this.userName);
    this.router.navigate(['home']);
  }
}
