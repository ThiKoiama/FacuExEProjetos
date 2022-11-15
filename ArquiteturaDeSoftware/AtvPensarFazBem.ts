class Work {
  private Name: string;
  private Type: string;

  constructor(pName: string, pType: string) {
    this.Name = pName;
    this.Type = pType;
  }

  public getName(): string {
    return this.Name;
  }

  public setName(pNome: string): void {
    this.Name = pNome;
  }

  public getType(): string {
    return this.Type;
  }

  public setType(pType: string): void {
    this.Type = pType;
  }
}

class Movie extends Work {
  private Duration: number;

  constructor(pDuration: number, pName: string, pType: string) {
    super(pName, pType);
    this.Duration = pDuration;
  }

  public getDuration(): number {
    return this.Duration;
  }

  public setDuration(pDuration: number): void {
    if (pDuration <= 0)
            throw new Error('Digite um número válido para a duração!');
    this.Duration = pDuration;
  }
}

class Serie extends Work {
  private totalEpisodes: number;

  constructor(pTotEp: number, pName: string, pType: string) {
    super(pName, pType);
    this.totalEpisodes = pTotEp;
  }

  public getTotEp(): number {
    return this.totalEpisodes;
  }

  public setTotEp(pTotEp: number): void {
    if (pTotEp <= 0)
            throw new Error('Digite um número válido para o número de episódios');
    this.totalEpisodes = pTotEp;
  }
}

class Season extends Serie {
  private Number: number;
  private Serie: Serie;

  constructor(
    pNumber: number,
    pSerie: Serie,
    pTotEp: number,
    pName: string,
    pType: string
  ) {
    super(pTotEp, pName, pType);
    this.Number = pNumber;
    this.Serie = pSerie;
  }

  public getNumber(): number {
    return this.Number;
  }

  public setNumber(pNumber: number): void {
    if (pNumber <= 0)
            throw new Error('Digite um número válido para o número da temporada!');
    this.Number = pNumber;
  }

  public getSerie(): Serie {
    return this.Serie;
  }

  public setSerie(pSerie: Serie): void {
    this.Serie = pSerie;
  }
}
