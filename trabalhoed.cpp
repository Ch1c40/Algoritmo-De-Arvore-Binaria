#include <iostream>

struct NO{
    int conteudo;
    struct NO *esq, *dir;
};
void preordem(NO *p){
    std::cout << p->conteudo << " ";
    if(p->esq)
        preordem(p->esq);
    if(p->dir)
        preordem(p->dir);
}
NO* Inserção(NO *p, int k){
    NO *R = new NO();
    R->conteudo = k;
    if(p == nullptr){
        p = R;
        return R;
    }
    NO *q1 = p;
    NO *q2 = nullptr;
    while (q1 != nullptr)
    {
        q2 = q1;
        if (q1->conteudo > k)
        {
            q1 = q1->esq;
        }
        else
        {
            q1 = q1->dir;
        }
        
    }
    if (q2->conteudo > k)
    {
        q2->esq = R;
    }
    else
    {
        q2->dir = R;
    }
    return p;
}
NO* criaArvore(int k){
    return Inserção(nullptr, k);
}
NO* Busca(NO* p, int k){
    NO* q = p;
    while (q->conteudo != k && q)
    {
        if (q->conteudo > k)
        {
            q = q->esq;
        }
        else
        {
            q = q->dir;
        }
        
    }
    if (!q)
    {
        return nullptr;
    }
    return q;
}
NO* Remocao(NO* p, int k){
    NO* q1 = p;
    NO* q2 = nullptr;
    NO* q3 = nullptr;
    if (!p || p->conteudo == k)
        return nullptr;

    if (p->conteudo == k)
        q2 = p;
    
    while (q1 != nullptr && q1->conteudo != k)
    {
        q2 = q1;
        if (q1->conteudo > k)
        {
            q1 = q1->esq;
        }
        else
        {
            q1 = q1->dir;
        }
        
    }
    if (q1 == nullptr)
    {
        return p;
    }
    q3 = q1->dir;
    while (q3->esq != nullptr)
    {
        q3 = q3->esq;
    }
    q3->esq = q1->esq;
    q2->esq = q1->dir;
    return p;
}

int main(){
    NO* raiz = Inserção(nullptr, 20);
    for (int i = 0; i < 8; i++)
    {
        int l;
        std::cout << "Digite os valores para a arvore: " << std::endl;
        std::cin >> l;
        Inserção(raiz, l);
    }
    preordem(raiz);
    std::cout << std::endl;
    int j;
    std::cout << "Digite um valor para buscar: " << std::endl;
    std::cin >> j;
    NO* B = Busca(raiz, j);
    if (B)
        std::cout << "Valor encontrado: " << B->conteudo;
    else
        std::cout << "Valor não encontrado.";
    std::cout << std::endl;
    int z;
    std::cout << "Digite um valor para remover: " << std::endl;
    std::cin >> z;
    Remocao(raiz, z);
    preordem(raiz);
}

