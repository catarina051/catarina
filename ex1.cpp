/*
Compilar com: g++ este_arquivo.cpp
./a.out ou ./a.exe
*/
#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <vector>
#include <algorithm> // Necessário para usar max()
#include <ctime>
#include <cstdlib>
#include <string>
#include <cctype>
#include "hash.h"
#include "./includes/Utilitaria.h"
#endif //final do arquivo

using namespace std;

void preencher(vector<int>& v, int min, int max) {
    for (int i = 0; i < v.size(); i++) {
        v[i] = min + rand() % (max - min + 1);
    }
}

int main() {

    srand(time(NULL));
    Utilitaria::colorir(Utilitaria::BOLD, Utilitaria::BLUE);
    cout << "--- Secao B: <iostream> e <string> ---" << endl;
    Utilitaria::resetarCor();
    Utilitaria::aguardar(1000); 
    Utilitaria::limparTela();
    string nome_arquivo;
    cout << "Digite um nome para o arquivo de teste: ";
    // cin >> nome_arquivo; // CUIDADO: Lê só UMA palavra
    getline(cin, nome_arquivo); // Jeito certo de ler UMA LINHA inteira
    cout << "Nome digitado: " << nome_arquivo << endl << endl;


    cout << "--- Secao C: <vector> ---" << endl;
    
    // Declara um vetor de 10 posições (inicializa com 1)
    vector<int> meu_vetor(10,1);
    vector<char> chaves {'N', 'I', 'O', 'V', 'Z', 'A', 'P', 'R', 'Q', 'S', 'T'}; 
    
    preencher(meu_vetor, 1, 99);
    
    cout << "Tamanho do vetor: " << meu_vetor.size() << endl;

    

    cout << "--- Secao G: <cctype> ---" << endl;
    char c1 = 'A';
    char c2 = 'b';
    char c3 = '5';
    
    if (isupper(c1)) cout << "'" << c1 << "' e MAIUSCULA." << endl;
    if (islower(c2)) cout << "'" << c2 << "' e minuscula." << endl;
    if (isdigit(c3)) cout << "'" << c3 << "' e um digito." << endl;

    // O "mapeamento" de char para índice
    int indice_A = c1 - 'A'; // 'A' - 'A' = 0
    int indice_b = c2 - 'a' + 26; // 'b' - 'a' + 26 = 1 + 26 = 27
    cout << "Indice de 'A' (0-25): " << indice_A << endl;
    cout << "Indice de 'b' (26-51): " << indice_b << endl << endl;


    // --- SEÇÃO H: ALGORITMOS PRONTOS (<algorithm>) ---
    // (Como nos seus códigos 2, 3)
    cout << "--- Secao H: <algorithm> ---" << endl;
    
    // std::swap (troca dois valores)
    int a = 10, b = 20;
    cout << "Antes: a=" << a << ", b=" << b << endl;
    swap(a, b);
    cout << "Depois: a=" << a << ", b=" << b << endl;

   
    cout << "--- FIM DO TEMPLATE ---" << endl;


    cout << "--- hashtable ---" << endl;
    HashTable tabela = criarTabela(11);//c++
    hashtable* tabela = inicializar(11);//c

     if(tabela == NULL) { //c
        printf("Falha ao alocar memoria.\n");
        return 1;
    }

    vector<char> chaves {'N', 'I', 'O', 'V', 'Z', 'A', 'P', 'R', 'Q', 'S', 'T'}; //c++
     char dados_para_inserir[] = {'A', 'B', 'K', 'C', 'L', 'Z'}; //c
     int n = sizeof(dados_para_inserir) / sizeof(dados_para_inserir[0]);//c

    for (int i = 0; i < chaves.size(); i++) {
        char c = chaves[i];
        int posInicial = H(c);
        int colisoes = inserir(tabela, c);
        

        cout << "Inserindo '" << c << "' -> h('" << c << "') = " << posInicial<<endl;
        if (colisoes > 0) {
            cout << " tivemos " << colisoes << " colisao(oes) na(s) posicao(oes):";
            int p = posInicial;
            for (int j = 0; j < colisoes; j++) {
                cout << " " << p;
                p++;
                if(p==tabela.table.size()) p=0;
            }
        } else {
            cout << "sem colisao";
        }
        cout << endl;

        mostrarTabela(tabela);
    }

    free(minha_tabela->table);//c
    free(minha_tabela); //c

    return 0;
}


cout << "--- Secao AVL ---" << endl;

#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;


   LÓGICA DOS PONTEIROS:
   - sae: Sub-Árvore Esquerda (valores menores)
   - sad: Sub-Árvore Direita (valores maiores)
   
   FATOR DE BALANCEAMENTO (FB):
   - FB = Altura(Esq) - Altura(Dir)
   - FB > 1: Pesado na Esquerda (Precisa girar p/ Direita)
   - FB < -1: Pesado na Direita (Precisa girar p/ Esquerda)


struct no {
    int info;
    no *sae;
    no *sad;
    int altura;
};

int altura(no *n) {
    if (n == NULL) return 0;
    return n->altura;
}

int fb(no* n) {
    if (n == NULL) return 0;
    return altura(n->sae) - altura(n->sad);
}

no* criar(int valor) { //c++
    no* n = new no;
    n->info = valor;
    n->sae = NULL; n->sad = NULL;
    n->altura = 1;
    return n;
}
no* criar(int valor) { //c
    no* n = (no*) calloc(1, sizeof(no));
    if(n != NULL) {
        n->info = valor;
        n->altura = 1;
    }

    return n;
}

no* rot_direita(no* n) {
    no* E = n->sae;
    no* temp = E->sad;

    E->sad = n;
    n->sae = temp;

    n->altura = max(altura(n->sae), altura(n->sad)) + 1;
    E->altura = max(altura(E->sae), altura(E->sad)) + 1;
    return E;
}

no* rot_esquerda(no* n) {
    no* D = n->sad;
    no* temp = D->sae;

    D->sae = n;
    n->sad = temp;

    n->altura = max(altura(n->sae), altura(n->sad)) + 1;
    D->altura = max(altura(D->sae), altura(D->sad)) + 1;
    return D;
}

no* inserir(no* n, int valor) {
    if (n == NULL) return criar(valor);

    if (valor < n->info)
        n->sae = inserir(n->sae, valor);
    else if (valor > n->info)
        n->sad = inserir(n->sad, valor);
    else 
        return n; 
    valor duplicado nao entra 

    n->altura = 1 + max(altura(n->sae), altura(n->sad));

   
    int bal = fb(n);

    if (bal > 1 && valor < n->sae->info)
        return rot_direita(n);

    if (bal < -1 && valor > n->sad->info)
        return rot_esquerda(n);

    if (bal > 1 && valor > n->sae->info) {
        n->sae = rot_esquerda(n->sae);
        return rot_direita(n);
    }

    if (bal < -1 && valor < n->sad->info) {
        n->sad = rot_direita(n->sad);
        return rot_esquerda(n);
    }

    return n;
}

no* remover(no *n, int valor) {
    if (n == NULL)
        return NULL;

    no *temp = NULL;
    if(valor > n->info) {
        n->sad = remover(n->sad, valor);
        if(fb(n) == 2) {
            if(fb(n->sae) >= 0)
                n = rot_direita(n);
            else {
                n->sae = rot_esquerda(n->sae);
                n = rot_direita(n);
            }
        }
    } else if(valor < n->info) {
        n->sae = remover(n->sae, valor);
        if(fb(n) == -2)  {
            if(fb(n->sad) <= 0)
                n = rot_esquerda(n);
            else {
                n->sad = rot_direita(n->sad);
                n = rot_esquerda(n);
            }
        }
    } else {
        if(n->sad != NULL) { 
            temp = n->sad;
            while(temp->sae != NULL)
                temp = temp->sae;
 
            n->info = temp->info;
            n->sad = remover(n->sad, temp->info);
            if(fb(n) == 2) {
                if(fb(n->sae) >= 0)
                    n = rot_direita(n);
                else {
                    n->sae = rot_esquerda(n->sae);
                    n = rot_direita(n);
                }
            }
        } else {
            return n->sae;
        }
    }
    n->altura = altura(n);
    return n;
}

void largura(no* n) {
    queue<no*> f;
    f.push(n);
    while(!f.empty()) {
        no* atual = f.front();
        cout << atual->info << " ";
        f.pop();
        if(atual->sae)
            f.push(atual->sae);
        if(atual->sad)
            f.push(atual->sad);
    }
}

void liberar(no** n) {
    if(n == NULL)
        return;
    
    no* temp = *n;
    liberar(&((*n)->sae));
    liberar(&((*n)->sad));
    free(temp);
}


void em_ordem(no *n) {
    if(n == NULL)
        return;

    em_ordem(n->sae);
    cout << n->info << " ";
    em_ordem(n->sad);
}

cout << "--- Secao programação dinamica ---" << endl;

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

vector<int> chamadas_por_n;
long long total_chamadas = 0;

ull fib_com_contagem(int n) {
    total_chamadas++;      
    chamadas_por_n[n]++;   
    if(n < 2)
        return n;
    
    return fib_com_contagem(n-1) + fib_com_contagem(n-2);
}

int main() {
    int N = 10;
    chamadas_por_n.resize(N + 1, 0);

    cout << "Calculando fib(" << N << ")..." << endl;
    ull resultado = fib_com_contagem(N);

    cout << "Resultado: " << resultado << endl;
    cout << "Total de chamadas recursivas: " << total_chamadas << endl;
    cout << "--------------------------------" << endl;
    cout << "Quantas vezes cada numero foi recalculado:" << endl;
    for(int i = 0; i <= N; i++) {
        cout << "fib(" << i << ") foi calculado: " << chamadas_por_n[i] << " vezes." << endl;
    }
    
    O numero de chamadas repetidas (inuteis) é: Total - (N+1)
    cout << "Chamadas repetidas (desperdicadas): " << total_chamadas - (N+1) << endl;

    return 0;
}


vector<int> memo(tamanho_do_problema, -1); 

int dp_top_down(int n) {

    if (n <= 1) return n;

    if (memo[n] != -1) return memo[n];

    memo[n] = dp_top_down(n-1) + dp_top_down(n-2);
    
    return memo[n];
}

int dp_bottom_up(int n) {
    vector<int> tab(n + 1);

    tab[0] = 0;
    tab[1] = 1;

    for (int i = 2; i <= n; i++) {
        tab[i] = tab[i-1] + tab[i-2]; 
    }

    return tab[n];
}

int main() {
    // --- Teste AVL --
    int valores[] = {10, 15, 20, 9, 5, 16, 17, 8, 6}, //{1, 2, 4, 5, 6, 3},
        tam = sizeof(valores)/sizeof(int);
    
    no * root = NULL;
    for(int i = 0; i < tam; i++) {
        root = inserir(root, valores[i]);
        cout << "largura: ";
        largura(root);
        cout << endl;
    }

    cout << "\nem ordem: ";
    em_ordem(root);
    cout << endl;

    cout << "\nremocao de 8 e 10 \n";
    root = remover(root, 8);
    root = remover(root, 10);

    cout << "em ordem: ";
    em_ordem(root);
    cout << endl;
    cout << "largura: ";
    largura(root);
    cout << endl;

    cout << "\nremocao de 15 \n";
    root = remover(root, 15);

    cout << "em ordem: ";
    em_ordem(root);
    cout << endl;
    cout << "largura: ";
    largura(root);

    // --- Teste DP ---
    int N = 10;
    
    // Preparando Top-Down
   // memo.assign(N + 1, -1); 
    cout << "Fib Top-Down(" << N << "): " << dp_top_down(N) << endl;

    // Teste Bottom-Up
    cout << "Fib Bottom-Up(" << N << "): " << dp_bottom_up(N) << endl;

    return 0;
}

bool buscaBinaria(vector<int> &v, int inicio, int fim, int valor)
{
    if (inicio > fim)
        return false;
    int meio = inicio + (fim - inicio) / 2;

    if (v[meio] == valor)
        return true;

    if (v[meio] > valor)
    {
        return buscaBinaria(v, inicio, meio - 1, valor);
    }
    else
    {
        return buscaBinaria(v, meio + 1, fim, valor);
    }
}

void bubbleSort(vector<int> &v)
{
    bool trocou = true;

    while (trocou)
    {
        trocou = false;
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] < v[i - 1])
            {
                swap(v[i], v[i - 1]);
                trocou = true;
            }
        }
    }
}

void insertion(vector <int>& v, int tam){
int chave = 0;
    for(int i=1; i<tam; i++){
        chave = v[i];
        int j = i-1;
        while(j>=0 && v[j]>chave){
            v[j+1] = v[j];
            j=j-1;     
        }
        
        v[j+1]=chave;
        
    }

}

void selectionSort(vector<int>& v) {
    int n = v.size();

    for (int i = 0; i < n - 1; i++) {
        
        int min_idx = i;

        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            swap(v[i], v[min_idx]);
        }
    }
}


void mergeSort(vector<int> &v, int inicio, int fim)
{
    if (inicio >= fim)
        return;
    int meio = inicio + (fim - inicio) / 2;
    mergeSort(v, inicio, meio);
    mergeSort(v, meio + 1, fim);
    merge(v, inicio, meio, fim);
}

void merge(vector<int> &v, int inicio, int meio, int fim)
{
    vector<int> aux(fim - inicio + 1);
    int idx1 = inicio, idx2 = meio + 1, k = 0;

    while (idx1 <= meio && idx2 <= fim)
    {
        if (v[idx1] <= v[idx2])
        {
            aux[k] = v[idx1++];
        }
        else
        {
            aux[k] = v[idx2++];
        }
        k++;
    }

    while (idx1 <= meio)
    {
        aux[k++] = v[idx1++];
    }
    while (idx2 <= fim)
    {
        aux[k++] = v[idx2++];
    }

    for (int i = inicio; i <= fim; i++)
    {
        v[i] = aux[i - inicio];
    }
}

void quicksort(vector<int> &v, int esq, int dir)
{
    if (esq >= dir)
        return;

    int p = particionamento(v, esq, dir);
    quicksort(v, esq, p - 1);
    quicksort(v, p + 1, dir);
}

int particionamento(vector<int> &v, int esq, int dir)
{
    int pivo = v[esq];
    int k = esq + 1;

    for (int atual = esq + 1; atual <= dir; atual++)
    {
        if (v[atual] < pivo)
        {
            swap(v[k], v[atual]);
            k++;
        }
    }

    swap(v[esq], v[k - 1]);

    return k - 1;
}

void heapsort(vector<int> &v, int n)
{
    maxheap(v, n);
    for (int i = n - 1; i > 0; i--)
    {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}

void maxheap(vector<int> &v, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(v, n, i);
    }
}

void heapify(vector<int> &v, int n, int idx)
{
    while (true)
    {
        int maior = idx, esq = 2 * idx + 1, dir = 2 * idx + 2;
        if (esq < n && v[esq] > v[maior])
            maior = esq;
        if (dir < n && v[dir] > v[maior])
            maior = dir;
        if (maior == idx)
            break;
        swap(v[maior], v[idx]);
        idx = maior;
    }
}

void counting_sort(vector<int> &v) {
    int maior = v[0], menor = v[0];

    for(int i = 1; i < v.size(); i++) {
        if(v[i] < menor)
            menor = v[i];
        if(v[i] > maior)
            maior = v[i];
    }

    vector<int> aux(maior - menor + 1);
    for(int i = 0; i < v.size(); i++)
        aux[v[i]-menor]++;
    
    for(int i = 1; i < aux.size(); i++)
        aux[i] += aux[i-1];
    
    vector <int> vet(v.size());
    for (int i = v.size()-1; i >= 0; i--) {
        int idx = v[i] - menor;
        int val = aux[idx];
        vet[val-1] = v[i];
        aux[idx]--;
    }

    for (int i = 0; i < v.size(); i++)
        v[i] = vet[i];
}


//-----------hash.h---------
//c++
struct HashTable {
    vector<char> table; 
};


HashTable criarTabela(int tamanho);
int H(char letra); 
int inserir(HashTable &h, char chave);
int buscar(HashTable &h, char chave);
int remover(HashTable &h, char chave);
void mostrarTabela(const HashTable &h);

//c
typedef struct hashtable hashtable;

hashtable* inicializar(int tam);
int hash(hashtable* ht, char key); 
int inserir(hashtable* h, char value); 
bool remover(hashtable* h, char value);
bool buscar(hashtable* h, char value);
void imprimir_tabela(hashtable* ht);

//----------hash.cpp--------
//c++
int H(char letra) {
    int k = toupper(letra) - 'A' + 1; //toupper transforma todas as letras em maiuscula
    return (k + 2) % 11; 
}

HashTable criarTabela(int tamanho) {
    HashTable h;
    h.table = vector<char>(tamanho, ' ');  //usar vector tira a necessidade de alocar e liberar memoria
    return h;
}

int inserir(HashTable &h, char chave) {
    int pos = H(chave);
    int colisoes = 0;
    int tentativas = 0;
    while (h.table[pos] != ' ' && h.table[pos] != chave && tentativas<h.table.size()) {
        pos++;
        colisoes++;
        tentativas++;
        if(pos == h.table.size())
            pos=0;
    }
    if (tentativas<h.table.size()){
    h.table[pos] = chave;
    } else {
        cout<<"nao foi possivel inserir "<<chave<<" na tabela pois ela esta cheia"<<endl;
    }
    return colisoes;
}

int buscar(HashTable &h, char chave) {
    int pos = H(chave);
    int tentativas = 0;

    while (h.table[pos] != ' ' && tentativas < h.table.size()) {
        if (h.table[pos] == chave)
            return pos;
        pos++;   
        if(pos == h.table.size()){
            pos=0;
        }
        tentativas++;
    }
    return -1;
}

int remover(HashTable &h, char chave) {
    int pos = buscar(h, chave);
    if (pos != -1) {
        h.table[pos] = ' ';
        return 1;
    }
    return 0;
}

void mostrarTabela(const HashTable &h) {
    cout << "Tabela Hash: | ";
   for (int i = 0; i < h.table.size(); i++) {
        cout << h.table[i] << " | ";
    }
    cout<<endl;
  
}

//c

#define EMPTY '\0'
#define DELETED '#'

struct hashtable {
    int size;
};

void imprimir_tabela(hashtable* ht) {
    printf("--- Tabela Hash (Tamanho: %d) ---\n", ht->size);
    for(int i = 0; i < ht->size; i++) {
        printf(" | %2d: ", i); 
        if(ht->table[i] == EMPTY) {
            printf("(vazio)");
        } else if (ht->table[i] == DELETED) {
            printf("(delet.)");
        } else {
            printf("  %c  ", ht->table[i]);
        }
        printf(" |\n");
    }
    printf("----------------------------------\n\n");
}

hashtable* inicializar(int tam) {
    hashtable *tabela = (hashtable*) malloc(sizeof(hashtable));
    if(tabela) {
        tabela->table = (char*) malloc(tam * sizeof(char));
        if(tabela->table == NULL) {
            free(tabela);
            return NULL;
        }
        tabela->size = tam;
        for(int i = 0; i < tabela->size; i++)
            tabela->table[i] = EMPTY; 
    }
    return tabela;
}

int hash(hashtable * ht, char key) {
    return (int)key % ht->size;
}

int inserir(hashtable* ht, char value) {
    int colisoes = 0;
    int id_original = hash(ht, value);
    int id_atual = id_original;

    while(ht->table[id_atual] != EMPTY && ht->table[id_atual] != DELETED) {
        
        if(ht->table[id_atual] == value) {
            printf("Info: Valor '%c' ja existe na tabela.\n", value);
            return 0;
        }
        
        colisoes++;
        id_atual = (id_atual + 1) % ht->size;

        if(id_atual == id_original) {
            return -1;
        }
    }
    ht->table[id_atual] = value;
    return colisoes;
}

bool buscar(hashtable* ht, char value) {
    int id_original = hash(ht, value);
    int id_atual = id_original;

    while(ht->table[id_atual] != EMPTY) {
        
        if(ht->table[id_atual] == value) {
            return true;
        }
        
        id_atual = (id_atual + 1) % ht->size; 

        if(id_atual == id_original) {
            return false;
        }
    }

    return false;
}

bool remover(hashtable* ht, char value) {
    int id_original = hash(ht, value);
    int id_atual = id_original;

    while(ht->table[id_atual] != EMPTY) {
        
        if(ht->table[id_atual] == value) {
            ht->table[id_atual] = DELETED; 
            return true;
        }
        
        id_atual = (id_atual + 1) % ht->size;

        if(id_atual == id_original) {
            return false; 
        }
    }

    return false; 
}
