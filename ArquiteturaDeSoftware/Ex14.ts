class Figurinha {
    private nomeJogador: string
    private selecao: string
    private posicao: string
    private numero: number
 
    constructor(nome: string, selecao: string, pos: string, num: number) {
       this.nomeJogador = nome
       this.selecao = selecao
       this.posicao = pos
       this.numero = num
    }

    public getNome(): string {
        return this.nomeJogador
    }
    public setNome(nome: string): void {
        this.nomeJogador = nome
    }
    public getSelecao(): string {
        return this.selecao
    }
    public setSelecao(selecao: string): void {
        this.selecao = selecao
    }
    public getPosicao(): string {
        return this.posicao
    }
    public setPosicao(pos: string): void {
        this.posicao = pos
    }
    public getNumero(): number {
        return this.numero
    }
    public setNumero(num: number): void {
        this.numero = num
    }
}