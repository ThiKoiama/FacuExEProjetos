import {movimento} from '../types/movimento'


export class Personagem {
    nome: string;
    tipo: string;

    constructor(_nome: string, _tipo: string){
        this.nome = _nome;
        this.tipo = _tipo;
    }

    exibirDados(){
        console.log(`personagem ${this.nome} eh do tipo ${this.tipo}`)
    }

    movimentar(movimento: movimento){
        console.log(`Personagem andou na ${movimento.direcao} ${movimento.passos} passos`)
    }
}
