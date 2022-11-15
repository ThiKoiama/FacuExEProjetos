class Alunos {
    private RA: number;
    private nome: string;
    private np1: number;
    private np2: number;
    private nt: number;
    private faltas: number;
    constructor(
      ra: number,
      nome: string,
      np1: number,
      np2: number,
      nt: number,
      faltas: number
    ) {
      this.RA = ra;
      this.nome = nome;
      if (np1 < 0 || np1 > 10) throw new Error("Valor da nota da p1 inválido!");
      this.np1 = np1;
      if (np2 < 0 || np2 > 10) throw new Error("Valor da nota da p2 inválido!");
      this.np2 = np2;
      if (nt < 0 || nt > 10)
        throw new Error("Valor da nota dos trabalhos inválido!");
      this.nt = nt;
      if (faltas < 0 || faltas > 20) throw new Error("Valor de faltas inválido");
      this.faltas = faltas;
    }
    public ObterMediaProvas(): number {
      return (this.np1 + this.np2) / 2;
    }
    public ObterMediaSemestral(): number {
      return (this.np1 * 4 + this.np2 * 4 + this.nt * 2) / 10;
    }
    public VerificarAprovacao(): boolean {
      if (this.ObterMediaSemestral() >= 5 && (this.faltas / 20) * 100 >= 75) {
        return true;
      } else {
        return false;
      }
    }
  }