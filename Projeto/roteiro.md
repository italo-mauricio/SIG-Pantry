## Roteiro do nosso projeto

### Pedimos para carinhosamente quem for ler este texto siga o passo a passo para o entendimento do projeto.

### Passo 1:

* O nosso programa é um sistema de controle de despensa doméstica, o qual é indicado que o cadastro seja feito apenas de uma pessoa da casa, daquela que realmente toma conta da organização e controle da despensa.
Inicialmente, ela faz o seu cadastro no sistema e o seu ID é o username que ela irá escolher (elaboramos uma função que não poderá ser cadastrado usernames iguais). 
### Passo 2:
    Após fazer o cadastro de usuários, ela cadastra os itens, em que o ID deste módulo é o próprio código de barras. 

### Passo 3:
    Os módulos de entrada e saída são para controle do estoque da despensa doméstica. Neste caso, todos estão vinculados ao mesmo arquivo do de itens (itens.dat). 
    O último módulo, que possui arquivo próprio, mas que está vinculado ao ID do usuário, é o “lista de compras”. Local onde o usuário irá consultar itens que estão com quantidade mínima no estoque (ainda será implementado) e os itens próximos ao vencimento (ainda está em execução). Posteriormente, ele pode montar a sua lista com a quantidade de itens que optar.