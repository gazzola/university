
data = load('dados/x01m.txt');
X = data(:, 1); 
y = data(:, 2);
[m,n] = size(X);

 % xind = [0:0.1:max(X)]
figure; 
plot(X, y, 'rx');


X = [ones(m,1), X];
[m,n] = size(X);

theta = [0; 0];
alpha = 0.0000001;


[tnovos, jh] = graddesc(X, y, theta, alpha);
ji = [1:length(jh)];

% COMO FICOU A LINHA:

hold on;
plot(X(:,2), X*tnovos, '-');


% Como ficou o j_iters
figure; 
hold off;
plot(ji, jh, 'r-')


% prever novos dados
xnovo = [1; 860];
xnovo' * tnovos



% grad desc, plot j(theta) de acordo com iters


