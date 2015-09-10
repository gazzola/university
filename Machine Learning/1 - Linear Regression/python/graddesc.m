function [theta, J_iters] = graddesc(X, y, theta, alpha)

[m,n] = size(X);
maxiters = 1000;
J_iters = [];

for k=1:maxiters
	A = hipotese(X, theta) - y;
	theta = theta - (alpha/m) * (X' * A); 
	J_iters(end+1) = custo(X, y, theta);
end

end
