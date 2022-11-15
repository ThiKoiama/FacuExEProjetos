"use strict";
class Horario {
    /*
    constructor()
    {
        this.hora = 0
        this.minuto = 0
        this.segundo = 0
    }
    */
    constructor(hr, mn, sg) {
        this.setHora(hr);
        this.setMinuto(mn);
        this.setSegundo(sg);
    }
    getHora() {
        return this.hora;
    }
    setHora(hr) {
        if (hr < 0 || hr > 23)
            throw new Error('Hora inválida');
        this.hora = hr;
    }
    getMinuto() {
        return this.minuto;
    }
    setMinuto(mn) {
        if (mn < 0 || mn > 59)
            throw new Error('Minuto inválido');
        this.minuto = mn;
    }
    getSegundo() {
        return this.segundo;
    }
    setSegundo(sg) {
        if (sg < 0 || sg > 59)
            throw new Error('Segundo inválido');
        this.segundo = sg;
    }
    getSegundosHorario() {
        return this.getHora() * 60 * 60 + this.getMinuto() * 60 + this.getSegundo();
    }
    // método que recebe um horário e retorna a diferença em segundos com o Horário do objeto atual
    calcularDiferenca(outro) {
        let qtdseg1, qtdseg2;
        qtdseg1 = this.getSegundosHorario();
        qtdseg2 = outro.getSegundosHorario();
        return qtdseg1 - qtdseg2;
    }
}
let hora;
hora = new Horario(22, 10, 0); // alocação dinâmica de memória
//hora.setHora(230)
console.log(hora.getHora(), hora.getMinuto(), hora.getSegundo());
let hora2;
hora2 = new Horario(22, 40, 0);
let dif = hora.calcularDiferenca(hora2);
console.log(dif);
