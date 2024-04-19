import { exame } from "./exame";

export class Aluno {
    nome: string;
  
  
     constructor(_nome: string) {
       this.nome = _nome;
    }
  
  
   mensagem(p1: exame) : string {
    var retorno : string
    retorno = `Olá ${this.nome}, você tirou a nota nota: ${p1.notaAluno} na materia ${p1.materia}`
    return retorno;
   }
  }
  
  