data = load('reglog/result_alphas.txt');
X = data(:,1);
Y = data(:,2);
Z = data(:,3);

A = meshgrid(X);
B = meshgrid(Y);
C = meshgrid(Z);

mesh(A, log(B), log(C));
xlabel('Grau do polinômio')
ylabel('Taxa de aprendizagem')
zlabel('Custo - J(W)')	

hold off;
figure;


data = load('reglog/result_accs.txt');
X = data(:,1);
Y = data(:,2);
Z = data(:,3);

A = meshgrid(X);
B = meshgrid(Y);
C = meshgrid(Z);

mesh(A,log(B),C);
xlabel('Grau do polinômio')
ylabel('Taxa de aprendizagem')
zlabel('Acurácia (%)')