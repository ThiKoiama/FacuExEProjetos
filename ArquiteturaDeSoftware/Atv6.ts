class Item {

    private codigo: number;
    private descricao: string;
    private dataAquisicao: string;
    private autores: string[];

    constructor(codigo: number, descricao: string, dataAquisicao: string, autores: string[]) {
        this.codigo = codigo;
        this.descricao = descricao;
        this.dataAquisicao = dataAquisicao;
        this.autores = autores;

    }
    /*metodos*/
    public getCodigo(): number {
        return this.codigo
    }
    public setCodigo(codigo: number): void {
        if (codigo <= 0)
            throw new Error('Número inválido');
        this.codigo = codigo
    }
    public getDescricao(): string {
        return this.descricao
    }

    public setDescricao(descricao: string): void {
        this.descricao = descricao
    }
    public getData(): string {
        return this.dataAquisicao
    }
    public setData(dataAquisicao: string): void {
        this.dataAquisicao = dataAquisicao
    }
    public getAutores(): string[] {
        return this.autores
    }
    public setAutores(autores: string[]): void {
        this.autores = autores
    }

}

class Publicacao extends Item {

    private editora: string;
    private anoPublicacao: number;

    constructor(codigo: number, descricao: string, dataAquisicao: string, autores: string[], editora: string, anoPublicacao: number) {
        super(codigo, descricao, dataAquisicao, autores)
        this.editora = editora;
        this.anoPublicacao = anoPublicacao

    }
    public getEditora(): string {
        return this.editora
    }

    public setEditora(editora: string): void {
        this.editora = editora
    }
    public getAnoPublicacao(): number {
        return this.anoPublicacao
    }
    public setAnoPublicacao(anoPublicacao: number): void {
        this.anoPublicacao = anoPublicacao

    }
}
class CD extends Item {

    private genero: string;
    private nomeMusicas: string[];

    constructor(codigo: number, descricao: string, dataAquisicao: string, autores: string[], genero: string, nomeMusicas: string[]) {
        super(codigo, descricao, dataAquisicao, autores)
        this.genero = genero
        this.nomeMusicas = nomeMusicas

    }
    /*metodos*/
    public getGenero(): string {
        return this.genero
    }

    public setGenero(genero: string): void {
        this.genero = genero
    }
    public getNomeMusicas(): string[] {
        return this.nomeMusicas
    }
    public setNomeMusicas(nomeMusicas: string[]): void {
        this.nomeMusicas = nomeMusicas
    }


}
class DVD extends Item {

    private tipo: string;
    private descGeral: string

    constructor(codigo: number, descricao: string, dataAquisicao: string, autores: string[], tipo: string, descGeral: string) {
        super(codigo, descricao, dataAquisicao, autores)
        this.tipo = tipo;
        this.descGeral = descGeral;

    }
    /*metodos*/
    public getTipo(): string {
        return this.tipo
    }

    public setTipo(tipo: string): void {
        this.tipo = tipo
    }
    public getDescGeral(): string {
        return this.descGeral
    }
    public setDescGeral(descGeral: string): void {
        this.descGeral = descGeral
    }



}
class Livro extends Publicacao {

    private qtdPaginas: number
    private genero: string

    constructor(codigo: number, descricao: string, dataAquisicao: string, autores: string[], editora: string, anoPublicacao: number, qtdPaginas: number, genero: string) {
        super(codigo, descricao, dataAquisicao, autores, editora, anoPublicacao)
        this.qtdPaginas = qtdPaginas
        this.genero = genero;
    }
    /*metodos*/
    public getPaginas(): number {
        return this.qtdPaginas
    }

    public setPaginas(paginas: number): void {
        if (paginas <= 0)
            throw new Error('Págianas tem que ser maior que 0');
        this.qtdPaginas = paginas
    }
    public getGenero(): string {
        return this.genero
    }
    public setSenero(genero: string): void {
        this.genero = genero
    }




}
class Revista extends Publicacao {

    private volume: number;
    private priAssuntos: string[]

    constructor(codigo: number, descricao: string, dataAquisicao: string, autores: string[], editora: string, anoPublicacao: number, volume: number, priAssuntos: string[]) {
        super(codigo, descricao, dataAquisicao, autores, editora, anoPublicacao)
        this.volume = volume
        this.priAssuntos = priAssuntos

    }
    /*metodos*/
    public getVolume(): number {
        return this.volume
    }

    public setVolume(volume: number): void {
        if (volume < 0)
            throw new Error('Digite um número válido para volume');
        this.volume = volume
    }
    public getAssuntos(): string[] {
        return this.priAssuntos
    }
    public setAssuntos(assuntos: string[]): void {
        this.priAssuntos = assuntos
    }



}

const livro = new Livro(12,"Livro teste", "10/12/2004",['João', 'Maria'],'Editora teste',2000,50,'Terror')
const revista = new Revista(123,"Revista teste","10/12/2001",["Thiago", "Ana"],"Blue",2000,2,["teste1", "teste2"] )
const cd = new CD(1234,"cd teste", "10/10/2001", ["João", "Maria"],"Funk",['musica1', 'musica2'] )
const dvd = new DVD(2131, 'dvd teste', '20/10/2003', ['zé', 'jão'],'cd de testes','teste teste')

console.log(livro.getAnoPublicacao(), revista.getAutores(), cd.getCodigo(), dvd.getDescGeral())


