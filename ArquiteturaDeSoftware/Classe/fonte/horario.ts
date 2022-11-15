class Horario {
    private hora!: number
    private minuto!: number
    private segundo!: number
    /*
    constructor()
    {
        this.hora = 0
        this.minuto = 0
        this.segundo = 0
    }
    */
    constructor(hr: number, mn: number, sg: number) {
        this.setHora(hr)
        this.setMinuto(mn)
        this.setSegundo(sg)
    }

    public getHora(): number {
        return this.hora
    }
    public setHora(hr: number): void {
        if (hr < 0 || hr > 23)
            throw new Error('Hora inválida')
        this.hora = hr
    }
    public getMinuto(): number {
        return this.minuto
    }
    public setMinuto(mn: number): void {
        if (mn < 0 || mn > 59)
            throw new Error('Minuto inválido')
        this.minuto = mn
    }
    public getSegundo(): number {
        return this.segundo
    }
    public setSegundo(sg: number): void {
        if (sg < 0 || sg > 59)
            throw new Error('Segundo inválido')
        this.segundo = sg
    }

    public getSegundosHorario(){
        return this.getHora()*60*60 + this.getMinuto()*60 + this.getSegundo()
       
    }

    // método que recebe um horário e retorna a diferença em segundos com o Horário do objeto atual
    public calcularDiferenca(outro: Horario): number{
       let qtdseg1, qtdseg2: number
       qtdseg1 = this.getSegundosHorario()
       qtdseg2 = outro.getSegundosHorario()

       return qtdseg1 - qtdseg2;

    }


}

let hora: Horario
hora = new Horario(22,10,0) // alocação dinâmica de memória
//hora.setHora(230)
console.log(hora.getHora(), hora.getMinuto(), hora.getSegundo())

let hora2: Horario
hora2 = new Horario(22,40,0)

let dif = hora.calcularDiferenca(hora2)
console.log(dif)
