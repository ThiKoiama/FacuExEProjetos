import { Aluno } from "./Aluno";

const alunoF = new Aluno("Seu nome");
console.log(alunoF.mensagem({ materia: "Desenvolvimento de Framework III", notaAluno: 10 }));