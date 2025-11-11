/*
Compilar com: g++ este_arquivo.cpp
./a.out ou ./a.exe
*/
#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cctype>
#include "hash.h"
#include "./includes/Utilitaria.h"
#endif //final do arquivo

using namespace std;
using namespace std::chrono;

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

    cout << "--- Secao D: <chrono> ---" << endl;
    
    srand(time(NULL));
    const int TAM_MAX = 1000000;
    
    vector<int> v_mestre(TAM_MAX);
    preencher(v_mestre, 1, TAM_MAX); 

    fstream fout_quick("quick.txt");
    fstream fout_merge("merge.txt");

    if (!fout_quick.is_open() || !fout_merge.is_open()) {
        cout << "Erro ao abrir arquivos de saida." << endl;
        return 1;
    }

    cout << "Iniciando benchmarking..." << endl;

    for (int n = 10000; n <= TAM_MAX; n += 10000) {
        
        cout << "Testando para N = " << n << endl;

        vector<int> v_copia_quick = v_mestre;
        vector<int> v_copia_merge = v_mestre;

        auto ini_q = high_resolution_clock::now();
        quicksort(v_copia_quick, 0, n - 1); // IMPORTANTE: usar 'n-1'
        auto fim_q = high_resolution_clock::now();
        duration<double> t_q = fim_q - ini_q;

        fout_quick << n << " " << duration_cast<milliseconds>(t_q).count() / 1000.0 << endl;

        auto ini_m = high_resolution_clock::now();
        mergeSort(v_copia_merge, 0, n - 1);
        auto fim_m = high_resolution_clock::now();
        duration<double> t_m = fim_m - ini_m;
        fout_merge << n << " " << duration_cast<milliseconds>(t_m).count() / 1000.0 << endl;
    }

    fout_quick.close();
    fout_merge.close();

    cout << "Benchmarking concluido." << endl;


    cout << "--- Secao E: <fstream> (Escrita) ---" << endl;

   
    // Se não usar "ios::app", ele SOBRESCREVE o arquivo.
    fstream arquivo_saida(nome_arquivo + ".txt", ios::out | ios::app);

    if (!arquivo_saida.is_open()) {
        cout << "ERRO: Nao consegui abrir o arquivo para escrita!" << endl;
    } else {
        arquivo_saida << "--- Log de Teste ---" << endl;
        arquivo_saida << "Tempo de ordenacao: " << segundos << "s" << endl;
        arquivo_saida << "Tamanho do vetor: " << v_grande.size() << endl;

        arquivo_saida.close();
        cout << "Dados de benchmarking salvos em '" << nome_arquivo << ".txt'" << endl;
        cout << endl;
    }



    cout << "--- Secao F: <fstream> (Leitura) ---" << endl;

    // "ifstream" é específico para LEITURA
    ifstream arquivo_entrada(nome_arquivo + ".txt");

    if (!arquivo_entrada.is_open()) {
        cout << "ERRO: Nao consegui ler o arquivo '" << nome_arquivo << ".txt'" << endl;
    } else {
        // Exemplo 1: Ler LINHA POR LINHA
        cout << "Lendo o arquivo linha por linha:" << endl;
        string linha_lida;
        while (getline(arquivo_entrada, linha_lida)) {
            cout << "  [LINHA] " << linha_lida << endl;
        }
        arquivo_entrada.close(); // Fecha para reabrir do começo

        // Exemplo 2: Ler CARACTERE POR CARACTERE
        cout << "\nLendo o arquivo caractere por caractere:" << endl;
        arquivo_entrada.open(nome_arquivo + ".txt"); // Reabre o arquivo
        char letra;
        while (arquivo_entrada.get(letra)) { // 'get' pega um char
            cout << letra;
        }
        arquivo_entrada.close();
        cout << endl << endl;
    }

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
