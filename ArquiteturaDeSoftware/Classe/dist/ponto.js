"use strict";
class Ponto {
    constructor(x, y) {
        this.x = x;
        this.y = y;
    }
    calcularDistancia(p) {
        return Math.sqrt(Math.pow(p.x - this.x, 2) + Math.pow(p.y - this.y, 2));
    }
}
const p1 = new Ponto(10, 5);
const p2 = new Ponto(7, 3);
console.log(p1.calcularDistancia(p2));
