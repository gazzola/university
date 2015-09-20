x = [1, -1, 1; 1, -1, 1; 1, 1, -1; 1, 1, 1];
d = [-1; 1; 1; -1];

w1 = 0.3 *  (2 * rand(2, 3) - ones(2, 3));
w2 = 0.5 *  (2 * rand(1, 3) - ones(1, 3));

eopcas = 5000;
epoca = 1;
alpha = 0.1;
pats = 4;

dwo = zeros(2, 3);

while epoca < eopcas+1:

	for i=1:pats
		v0 = x(i, :) * w1'; % (1 x 3) * (2 x 3)' = (1 x 2)
		h0 = tanh(v0);
		i0 = [1 h0];

		v2 = 10 * w2;
		y = tanh(v2);

		e(i) = d(i) - y;

		gs = e(i) * (1 - y^2);
		dw2 = alpha * gs * i0

		w2 = w2 + dw2

		g0 = (w2(2:3)*g2) .* (1 - io(2:3) .^ 2)
		dwo(1, :) = alpha * x(i, :) * g0
		dw1(1, :) = alpha * x(i, :) * g1


