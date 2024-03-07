class AlgoritmoGenetico {
  constructor(cidades, populacaoSize, taxaMutacao) {
    this.cidades = cidades;
    this.populacaoSize = populacaoSize;
    this.taxaMutacao = taxaMutacao;
    this.populacao = this.inicializarPopulacao();
  }

  inicializarPopulacao() {
    const populacao = [];
    for (let i = 0; i < this.populacaoSize; i++) {
      const rotaAleatoria = this.gerarRotaAleatoria();
      populacao.push(rotaAleatoria);
    }
    return populacao;
  }

  gerarRotaAleatoria() {
    return this.cidades.slice().sort(() => Math.random() - 0.5);
  }

  calcularAptidao(rota) {
    let distanciaTotal = 0;
    let prioridadeTotal = 0;

    for (let i = 0; i < rota.length - 1; i++) {
      const cidadeAtual = rota[i];
      const proximaCidade = rota[i + 1];

      const distanciaEntreCidades = this.obterDistancia(
        cidadeAtual,
        proximaCidade
      );

      distanciaTotal += distanciaEntreCidades;

      if (cidadeAtual.prioridade) {
        prioridadeTotal += 2;
      }
    }

    const pesoDistancia = 1 / distanciaTotal;
    const pesoPrioridade = prioridadeTotal / rota.length;

    const pesoTotal = pesoDistancia * pesoPrioridade;

    return pesoTotal;
  }

  obterDistancia(cidadeA, cidadeB) {
    return Math.abs(cidadeA.posicao - cidadeB.posicao);
  }

  cruzar(pai1, pai2) {
    const pontoCorte1 = Math.floor(Math.random() * pai1.length);
    const pontoCorte2 = Math.floor(Math.random() * pai1.length);

    const inicio = Math.min(pontoCorte1, pontoCorte2);
    const fim = Math.max(pontoCorte1, pontoCorte2);

    const filho = Array.from({ length: pai1.length });

    for (let i = inicio; i <= fim; i++) {
      filho[i] = pai1[i];
    }

    let indiceFilho = 0;
    for (let i = 0; i < pai2.length; i++) {
      if (!filho.includes(pai2[i])) {
        while (filho[indiceFilho] !== undefined) {
          indiceFilho++;
        }
        filho[indiceFilho] = pai2[i];
      }
    }

    return filho;
  }

  mutar(rota) {
    const indice1 = Math.floor(Math.random() * rota.length);
    const indice2 = Math.floor(Math.random() * rota.length);
    [rota[indice1], rota[indice2]] = [rota[indice2], rota[indice1]];
  }

  executarGeracoes(numGeracoes) {
    for (let geracao = 0; geracao < numGeracoes; geracao++) {
      this.populacao = this.evolverPopulacao();
    }

    return this.populacao[0];
  }

  evolverPopulacao() {
    const novaPopulacao = [];

    const elitismo = 2;
    const melhoresIndividuos = this.populacao
      .map((rota) => ({ rota, aptidao: this.calcularAptidao(rota) }))
      .sort((a, b) => b.aptidao - a.aptidao)
      .slice(0, elitismo)
      .map((melhor) => melhor.rota);

    novaPopulacao.push(...melhoresIndividuos);

    while (novaPopulacao.length < this.populacaoSize) {
      const pai1 = this.selecionarPai();
      const pai2 = this.selecionarPai();
      const filho = this.cruzar(pai1, pai2);

      if (Math.random() < this.taxaMutacao) {
        this.mutar(filho);
      }

      novaPopulacao.push(filho);
    }

    return novaPopulacao;
  }

  selecionarPai() {
    const somaAptidoes = this.populacao.reduce(
      (soma, rota) => soma + this.calcularAptidao(rota),
      0
    );
    let pontoDeSelecao = Math.random() * somaAptidoes;

    for (const rota of this.populacao) {
      pontoDeSelecao -= this.calcularAptidao(rota);
      if (pontoDeSelecao <= 0) {
        return rota;
      }
    }
  }
}

const cidades = [
  { nome: "Jundiaí", posicao: 0, prioridade: false },
  { nome: "Itupeva", posicao: 15, prioridade: false },
  { nome: "Várzea Paulista", posicao: 10, prioridade: false },
  { nome: "Cabreúva", posicao: 20, prioridade: false },
  { nome: "Campo Limpo Paulista", posicao: 30, prioridade: false },
  { nome: "Jarinu", posicao: 50, prioridade: false },
  { nome: "Campinas", posicao: 70, prioridade: false },
  { nome: "São Paulo", posicao: 90, prioridade: false },
];

function iniciarAlgoritmoGenetico() {
  const numGeracoes = parseInt(document.getElementById("geracoes").value, 10);
  const taxaMutacao = parseFloat(document.getElementById("taxaMutacao").value);

  const algoritmoGenetico = new AlgoritmoGenetico(cidades, 150, taxaMutacao);
  const melhorRotaEncontrada = algoritmoGenetico.executarGeracoes(numGeracoes);

  const prioridadeJundiai =
    document.getElementById("prioridadeJundiai").checked;

  const prioridadeItupeva =
    document.getElementById("prioridadeItupeva").checked;

  const prioridadeVarzea = document.getElementById("prioridadeVarzea").checked;

  const prioridadeCabreuva =
    document.getElementById("prioridadeCabreuva").checked;

  const prioridadeCampoLimpo = document.getElementById(
    "prioridadeCampoLimpo"
  ).checked;

  const prioridadeJarinu = document.getElementById("prioridadeJarinu").checked;

  const prioridadeCampinas =
    document.getElementById("prioridadeCampinas").checked;

  const prioridadeSP = document.getElementById("prioridadeSP").checked;

  cidades[0].prioridade = prioridadeJundiai;
  cidades[1].prioridade = prioridadeItupeva;
  cidades[2].prioridade = prioridadeVarzea;
  cidades[3].prioridade = prioridadeCabreuva;
  cidades[4].prioridade = prioridadeCampoLimpo;
  cidades[5].prioridade = prioridadeJarinu;
  cidades[6].prioridade = prioridadeCampinas;
  cidades[7].prioridade = prioridadeSP;

  exibirResultado(melhorRotaEncontrada);
}

function exibirResultado(melhorRota) {
  const resultadoDiv = document.getElementById("resultado");
  resultadoDiv.innerHTML = "<h2>Melhor rota encontrada:</h2>";

  const ol = document.createElement("ol");
  melhorRota.forEach((cidade) => {
    const li = document.createElement("li");
    li.textContent = cidade.nome;
    ol.appendChild(li);
  });

  resultadoDiv.appendChild(ol);
}
