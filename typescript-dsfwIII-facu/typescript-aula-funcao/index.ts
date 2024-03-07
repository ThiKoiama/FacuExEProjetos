import {movimento} from './src/types/movimento'
import {direcao} from './src/types/direcao'
import { Personagem } from './src/model/Personagem';


function exibirMensagem() {
    console.log("Hello World")
}
exibirMensagem();
exibirMensagem();
exibirMensagem();
exibirMensagem();


function exibirMensagemComParametro(mensagem:string, nome: string){ 
    console.log(`${mensagem}, ${nome}`)
    
}
exibirMensagemComParametro("Olá", "Thiago")

function calcularNovoPreco(precoOriginal: number, taxaReajuste: number): string{
    const novoPreco = precoOriginal * (1+taxaReajuste/100);

    return `O novo preço é ${novoPreco}`
}

const novoPreco = calcularNovoPreco(10, 50)
console.log(novoPreco)



// types

//type direcao = "cima" | "baixo" | "direita" | "esquerda";

type movimentacao = {
direcao: direcao;
passos: number
}

function Movimentar (movimentacao: movimentacao){ 
    console.log(`Andou na direção ${movimentacao.direcao}, ${movimentacao.passos} passos`)
    
}

Movimentar({direcao: "direita", passos: 5})

//classe

const hulk = new Personagem('hulk', 'puto')
hulk.exibirDados();
hulk.movimentar({direcao: "esquerda", passos: 2})
hulk.movimentar({direcao: "direita", passos: 2})


const loki = new Personagem('loki', 'vilão')
loki.exibirDados();
loki.movimentar({direcao: "baixo", passos: 1})

