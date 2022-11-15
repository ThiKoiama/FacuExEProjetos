class Prova {
    private nota: number
    private peso: number

    constructor(nota: number, peso: number) {
        this.nota = nota
        this.peso = peso
    }

    public getNota(): number {
        return this.nota
    }
    public getPeso(): number {
        return this.peso
    }

    public setNota(nota: number): void {
        if (nota < 0 || nota > 10)
            throw new Error('Nota inválida')
        this.nota = nota
    }
    public setPeso(peso: number): void {
        this.peso = peso
    }

    public getValor(): number {
        let valorFinal: number
        valorFinal = (this.nota * this.peso) / this.peso
        return valorFinal
    }
}

class Estudante {
    private nome: string
    private ra: number
    private provateorica: number
    private provapratica: number
    private provafinal: number

    constructor(nome: string, ra: number, provateorica: number, provapratica: number, provafinal: number) {
        this.nome = nome
        this.ra = ra
        this.provateorica = provateorica
        this.provapratica = provapratica
        this.provafinal = provafinal
    }

    public getNome(): string {
        return this.nome
    }
    public setNome(nome: string): void {
        this.nome = nome
    }
    public getRA(): number {
        return this.ra
    }
    public setRA(RA: number): void {
        this.ra = RA
    }

    public getProvateorica(): number {
        return this.provateorica
    }

    public setProvateorica(provateorica: number): void {
        this.provateorica = provateorica
    }
    public getProvapratica(): number {
        return this.provapratica
    }

    public setProvapratica(provapratica: number): void {
        this.provapratica = provapratica
    }
    public getProvafinal(): number {
        return this.provafinal
    }

    public setProvafinal(provafinal: number): void {
        this.provafinal = provafinal
    }
    public isAprovado() {
        let total: number
        total = this.provafinal + this.provapratica + this.provateorica
        if (total >= 6) {
            console.log("Aprovado")
        } else {
            console.log("Reprovado")
        }
    }

}

var Prova1 = new Prova(10, 30);
var Estudante1 = new Estudante("João", 121212, 4, 10, 4)
Estudante1.isAprovado();
