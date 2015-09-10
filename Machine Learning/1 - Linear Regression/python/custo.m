function J = custo(X, y, theta)

[m,n] = size(X);
hx = hipotese(X, theta);
J = sum((hx - y) .^ 2)/(2*m);

end
