# Sistema de Gestão Scrum (User Stories)

Este projeto em C++ tem como objetivo prover suporte à gestão de projetos utilizando o framework Scrum, permitindo o cadastro de usuários e a gerência de requisitos baseada em histórias de usuário.

## 📝 Descrição do Sistema
O software permite que cada usuário crie uma conta informando e-mail, nome, senha e papel (role) no projeto. Os papéis disponíveis são:
* **Proprietário do Produto** (Product Owner)
* **Mestre Scrum** (Scrum Master)
* **Desenvolvedor** (Developer)

Para acessar os serviços do sistema, o usuário deve realizar a autenticação informando seu e-mail e senha cadastrados. Após autenticado, o usuário tem acesso aos serviços de gestão.

## 🚀 Como baixar e abrir o projeto

Siga os passos abaixo para configurar o ambiente no seu computador:
1. **Instalar e configurar git e GitHub**
   Guia prático: [Git na Prática — Um Guia Completo e Explicado para Iniciantes](https://medium.com/@hitoshyamamoto/git-na-pr%C3%A1tica-um-guia-completo-e-explicado-para-iniciantes-7cdaf1914e1f)
2. **Clonar o repositório:**
   Abra o seu terminal (ou Git Bash) e execute o comando:
   ```bash
   git clone https://github.com/edulucca/tp1-gestao-scrum.git   ```
3. **Abrir no Code::Blocks**

    Abra o software Code::Blocks.

    Vá no menu superior: File -> Open....

    Navegue até a pasta onde o projeto foi clonado.

    Selecione o arquivo com a extensão .cbp (ex: gestaoscrum.cbp) e clique em abrir.

4. **Compilar e Executar**

    Com o projeto aberto, pressione a tecla F9 (ou clique no ícone de engrenagem com o "play" azul na barra de ferramentas).

## Atividades a Realizar

   O desenvolvimento do projeto segue o seguinte cronograma de atividades:

    [ ] Projetar, codificar e documentar classes domínio (domain classes).

    [ ] Projetar, codificar e documentar classes entidade (entity classes).

    [ ] Construir modelo de arquitetura, codificar e documentar as interfaces entre módulos.

    [ ] Projetar e codificar a camada de apresentação.

    [ ] Projetar e codificar a camada de serviço.

    [ ] Criar vídeo demonstrando a execução com sucesso do teste fumaça (smoke test) do código integrado.

## ⚠️ Observações para Colaboradores

    Não delete o arquivo .cbp: Ele é o arquivo de projeto essencial para que o Code::Blocks reconheça os arquivos e as configurações de compilação em qualquer computador.

    Adição de arquivos: Sempre que criar um novo arquivo .cpp ou .hpp, faça-o por dentro da IDE (File > New > File) ou clique com o botão direito no projeto e selecione Add files.... Isso garante que o arquivo seja registrado no .cbp e sincronizado corretamente via Git.
  
