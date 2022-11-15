
class Pessoa {

    
    private endereco!: string;
    private telefone!: string;
    private email!: string;
    private id!: number;


    constructor(endereco: string, telefone: string, email: string, id: number) {

      
        this.setEndereco(endereco);

        this.setTelefone(telefone);

        this.setEmail(email);

        this.setId(id);
    }

    public getEndereco(): string {
        return this.endereco;
    }

    public setEndereco(endereco: string): void {
        if (endereco.trim().length == 0)
            throw new Error('Endereço não pode ser vazio');

        this.endereco = endereco;
    }

    public getTelefone(): string {
        return this.telefone;
    }

    public setTelefone(telefone: string): void {
        if (telefone.trim().length == 0)
            throw new Error('Telefone não pode ser vazio');

        this.telefone = telefone;
    }

    public getEmail(): string {
        return this.email;
    }

    public setEmail(email: string): void {
        if (email.trim().length == 0)
            throw new Error('Email não pode ser vazio');

        this.email = email;
    }


    public getId(): number {
        return this.id;
    }

    public setId(id: number): void {
        if (id == null)
            throw new Error('ID não pode ser vazio');

        this.id = id;
    }


}

class PessoaFisica extends Pessoa {

    private cpf!: number;
    private nome!: string;

    constructor(endereco: string, telefone: string, email: string, id: number, cpf: number, nome: string) {
        super(endereco, telefone, email, id) 

        this.setCpf(cpf);
        this.setNome(nome);

    }

    public getCpf(): number {
        return this.cpf
    }

    public setCpf(cpf: number): void {
        if (cpf == null)
            throw new Error('CPF não pode ser vazio');
        this.cpf = cpf;
    }

    public getNome(): string {
        return this.nome
    }

    public setNome(nome: string): void {
        if (nome == null)
            throw new Error('Nome não pode ser vazio');
        this.nome = nome;
    }
}

class PessoaJuridica extends Pessoa {

    private cnpj!: string;
    private razaoSocial!: string;
    private faturamento!: string;

    constructor(endereco: string, telefone: string, email: string, id: number, cnpj: string, razaoSocial: string, faturamento: string) {
        super(endereco, telefone, email, id) 
        this.setcnpj(cnpj);
        this.setrazaoSocial(razaoSocial);
        this.setfaturamento(faturamento);

    }

    public getcnpj(): string {
        return this.cnpj
    }

    public setcnpj(cnpj: string): void {
        if (cnpj == null)
            throw new Error('CNPJ não pode ser vazio');
        this.cnpj = cnpj;
    }

    public getrazaoSocial(): string {
        return this.razaoSocial
    }

    public setrazaoSocial(razaoSocial: string): void {
        if (razaoSocial == null)
            throw new Error('Razão Social não pode ser vazia');
        this.razaoSocial = razaoSocial;
    }

    public getfaturamento(): string {
        return this.cnpj
    }

    public setfaturamento(faturamento: string): void {
        if (faturamento == null)
            throw new Error('Faturamento não pode ser vazio');
        this.faturamento = faturamento;
    }


}

