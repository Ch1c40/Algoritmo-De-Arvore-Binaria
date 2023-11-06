#include <iostream>

struct NO {
  int conteudo;
  struct NO *esq, *dir;
};
void preordem(NO *p) {
  std::cout << p->conteudo << " ";
  if (p->esq)
    preordem(p->esq);
  if (p->dir)
    preordem(p->dir);
}
NO *Insercao(NO *p, int k) {
  NO *R = new NO();
  R->conteudo = k;
  if (p == nullptr) {
    p = R;
    return R;
  }
  NO *q1 = p;
  NO *q2 = nullptr;
  while (q1 != nullptr) {
    q2 = q1;
    if (q1->conteudo > k) {
      q1 = q1->esq;
    } else {
      q1 = q1->dir;
    }
  }
  if (q2->conteudo > k) {
    q2->esq = R;
  } else {
    q2->dir = R;
  }
  return p;
}

NO *Busca(NO *p, int k) {
  NO *q = p;
  while (q && q->conteudo != k) {
    if (q->conteudo > k) {
      q = q->esq;
    } else {
      q = q->dir;
    }
  }
  if (!q) {
    return nullptr;
  }
  return q;
}

NO* Remocao(NO* p, int k){
  if(p == nullptr)
    return p;

  if(p->conteudo > k){
    p->esq = Remocao(p->esq, k);
    return p;
  }
  else if (p->conteudo < k){
    p->dir = Remocao(p->dir, k);
    return p;
  }
  if(p->esq == nullptr){
    NO* q1 = p->dir;
    delete p;
    return q1;
  }
  else if(p->dir == nullptr){
    NO* q1 = p->esq;
    delete p;
    return q1;
  }
  else{
    NO* q2 = p;
    NO* q3 = p->esq;
    while(q3->dir != nullptr){
      q2 = q3;
      q3 = q3->dir;
    }
    if(q2 != p)
      q2->dir = q3->esq;
    
    else
      q2->esq = q3->esq;
    
    p->conteudo = q3->conteudo;  

    delete q3;
    return p;
  }
    
}

int main() {
    NO *raiz = nullptr;
    NO *B;
    while (true){
        int expression;
        std::cout << "\nEscolha oq deseja fazer:\n1.Inserção\n2.Busca\n3.Remoção\n4.Sair" << std::endl;
        std::cin >> expression;
        switch (expression)
        {
        case 1:
            int l;
            std::cout << "Digite os valores para a arvore: " << std::endl;
            std::cin >> l;
            raiz = Insercao(raiz, l);
            preordem(raiz);
            break;

        case 2:
            int j;
            std::cout << "Digite um valor para buscar: " << std::endl;
            std::cin >> j;
            B = Busca(raiz, j);
            if (B)
                std::cout << "Valor encontrado: " << B->conteudo;
            else
                std::cout << "Valor não encontrado.";
            std::cout << std::endl;
            break;

        case 3:
            int z;
            std::cout << "Digite um valor para remover: " << std::endl;
            std::cin >> z;
            raiz = Remocao(raiz, z);
            if(!raiz)
              std::cout << "Elemento não encontrado" << std::endl;
            else
              preordem(raiz);
            break;

        case 4:
            return 1;
        default:
            std::cout << "Input não encontrado." << std::endl;
            break;
        }
    }
}
