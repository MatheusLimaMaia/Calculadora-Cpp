#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cmath>

int contarCasasDecimais(double numero){
	const int maxCasas = 10;
	int casas = 0;
	double parteDecimal = numero - static_cast<long long>(numero);
	while(casas < maxCasas && std::fmod(parteDecimal * 10, 1.0) != 0.0){
		parteDecimal *= 10;
		casas++;
	}
	return casas;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::cout << std::fixed << std::setprecision(0);

    int parametro;
    double num1, num2;
    double soma, subtracao, multiplicacao, divisao, raiz, potencia;
	
	std::cout << "Digite (1) para soma\n";
    std::cout << "Digite (2) para subtração\n";
    std::cout << "Digite (3) para multiplicação\n";
    std::cout << "Digite (4) para divisão\n";
    std::cout << "Digite (5) para Raiz Quadrada\n";
    std::cout << "Digite (6) para Potenciação\n\n";
    
    std::cout << "Digite o número do operador: ";
    std::cin >> parametro;
    std::cout << "\nDigite o primeiro valor: ";
    std::cin >> num1;
    std::cout << "\nDigite o segundo valor: ";
    std::cin >> num2;

    std::cout << "\n";
    
    soma = num1 + num2;
    subtracao = num1 - num2;
    multiplicacao = num1 * num2;
	potencia = pow(num1, num2);

    if (parametro >= 1 && parametro <= 6) {
        if (parametro == 1) {
            std::cout << num1 << " + " << num2 << " = " << soma;
        }
        if (parametro == 2) {
            std::cout << num1 << " - " << num2 << " = " << subtracao;
        }
        if (parametro == 3) {
            std::cout << num1 << " X " << num2 << " = " << multiplicacao;
        }
        if (parametro == 4) {
            if (num2 != 0){
            	divisao = num1 / num2;
            	int casas = contarCasasDecimais(divisao);
                if (casas == 0){
					std::cout << num1 << " / " << num2 << " = " << std::fixed << std::setprecision(0) << divisao;
				}else{
					std::cout << num1 << " / " << num2 << " = " << std::fixed << std::setprecision(casas) << divisao;
				}
				}else{
	            	std::cout << "Erro: divisão por zero!";
			}
        }
        if (parametro == 5) {
            if (num1 >= 0){
            	raiz = sqrt(num1);
            	int casas = contarCasasDecimais(raiz);
            	if (casas == 0){
            		std::cout << "\u221A" << num1 << " = " << std::setprecision(0) << raiz;
				}else{
					std::cout << "\u221A" << num1 << " = " << std::setprecision(casas) << raiz;
				}
            	
			}else{
            	std::cout << "Não é possível calcular a raiz quadrada de um número negativo.";
			}       
        }
        if (parametro == 6) {
            std::cout << "A potência de " << num1 << " elevado a " << num2 << " é: " << potencia;
        }  
    }else {
        std::cout << "Digite um número de operação válido";
    }
    std::cout << "\n";
    system("PAUSE");
	return 0;    
}