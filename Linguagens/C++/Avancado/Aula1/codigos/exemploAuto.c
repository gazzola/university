/*
 * Universidade Federal de Pernambuco - UFPE
 * Centro de Informática - CIn
 * Centro Integrado de Tecnologia da Informação - CITi
 * Centro de Estudos e Sistemas Avançados do Recife - CESAR
 * Curso de C/C++ Avançado
 * Instrutor: Allan Lima - http://allanlima.wordpress.com
 *
 * exemploAuto.c - Mostra um exemplo de como utilizar a palavra reservada auto
 *                na declaração de nested functions.
 */

int somarQuadrado(int a, int b) {
    auto int quadrado(int); // protótipo da função

    // agora a função auto pode ser chamada antes de ser implementada
    int retorno = quadrado(a) + quadrado(b);

    int quadrado(int z) {
        return z * z;
    }

    return retorno;
}

int main() {
    printf("2^2 + 10^2 = %d\n", somarQuadrado(2,10));
    return 0;
}
