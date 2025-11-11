/*
Compilar com: g++ este_arquivo.cpp
./a.out ou ./a.exe
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void preencher(vector<int>& v, int min, int max) {
    for (int i = 0; i < v.size(); i++) {
        v[i] = min + rand() % (max - min + 1);
    }
}

int main() {

    srand(time(NULL));

    cout << "--- Secao B: <iostream> e <string> ---" << endl;
    string nome_arquivo;
    cout << "Digite um nome para o arquivo de teste: ";
    // cin >> nome_arquivo; // CUIDADO: Lê só UMA palavra
    getline(cin, nome_arquivo); // Jeito certo de ler UMA LINHA inteira
    cout << "Nome digitado: " << nome_arquivo << endl << endl;


    cout << "--- Secao C: <vector> ---" << endl;
    
    // Declara um vetor de 10 posições (inicializa com 1)
    vector<int> meu_vetor(10,1); 
    
    preencher(meu_vetor, 1, 99);
    
    cout << "Tamanho do vetor: " << meu_vetor.size() << endl;

    cout << "--- Secao D: <chrono> ---" << endl;
    
    // 1. Preparação
    srand(time(NULL));
    const int TAM_MAX = 1000000;
    
    // 2. Criar o vetor "mestre" com dados aleatórios
    vector<int> v_mestre(TAM_MAX);
    preencher(v_mestre, 1, TAM_MAX); // Sua função 'preencher'

    // 3. Abrir os arquivos de saída
    fstream fout_quick("quick.txt");
    fstream fout_merge("merge.txt");
    // fstream fout_heap("heap.txt");

    if (!fout_quick.is_open() || !fout_merge.is_open()) {
        cout << "Erro ao abrir arquivos de saida." << endl;
        return 1;
    }

    cout << "Iniciando benchmarking..." << endl;

    // 4. O Loop Principal de Benchmarking
    for (int n = 10000; n <= TAM_MAX; n += 10000) {
        
        cout << "Testando para N = " << n << endl;

        // 5. Criar cópias para cada algoritmo
        //    (Para garantir que todos ordenem o MESMO vetor)
        vector<int> v_copia_quick = v_mestre;
        vector<int> v_copia_merge = v_mestre;

        // --- Teste do Quicksort ---
        auto ini_q = high_resolution_clock::now();
        quicksort(v_copia_quick, 0, n - 1); // IMPORTANTE: usar 'n-1'
        auto fim_q = high_resolution_clock::now();
        duration<double> t_q = fim_q - ini_q;
        // Salva no arquivo: N (tamanho) e Tempo (em segundos)
        fout_quick << n << " " << duration_cast<milliseconds>(t_q).count() / 1000.0 << endl;

        // --- Teste do Merge Sort ---
        auto ini_m = high_resolution_clock::now();
        mergeSort(v_copia_merge, 0, n - 1);
        auto fim_m = high_resolution_clock::now();
        duration<double> t_m = fim_m - ini_m;
        fout_merge << n << " " << duration_cast<milliseconds>(t_m).count() / 1000.0 << endl;
    }

    // 6. Fechar tudo
    fout_quick.close();
    fout_merge.close();

    cout << "Benchmarking concluido." << endl;


    cout << "--- Secao E: <fstream> (Escrita) ---" << endl;

   
    // Se não usar "ios::app", ele SOBRESCREVE o arquivo.
    fstream arquivo_saida(nome_arquivo + ".txt", ios::out | ios::app);
    //ios::out -> modo de saída;

    // SEMPRE checar se o arquivo abriu
    if (!arquivo_saida.is_open()) {
        cout << "ERRO: Nao consegui abrir o arquivo para escrita!" << endl;
    } else {
        // Usa como se fosse o 'cout'
        arquivo_saida << "--- Log de Teste ---" << endl;
        arquivo_saida << "Tempo de ordenacao: " << segundos << "s" << endl;
        arquivo_saida << "Tamanho do vetor: " << v_grande.size() << endl;

        // SEMPRE fechar o arquivo
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

        // Exemplo 2: Ler CARACTERE POR CARACTERE (como no seu código 4)
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
    return 0;
}