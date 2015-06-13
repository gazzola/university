/*

1) Pode cair num minimo local, se os pontos estiverem
   dispostos da maneira abaixo no grafico f(x) = y.

 Y
 |     .
 |        .
 |        .
 |
 |       .
 |________________ X 
 


2) Pode acontecer de que o ultimo elemento se casa com a
   penultima combinacao. Apois isso esses dois elementos
   sao descartados e eh feito a mesma coisa com n-2 pontos,
   e o total de tentativas eh justamente comecar por n pontos e
   intercalar suas ordens, ou seja:

   C(n, k) * A(n, k) = n!
   portanto a complexidade eh: n!/2 = O(n!)
   e no pior caso n = 16, temos entao 16!

   e vai levar um tempo de aproximadamente:
   20922789888000 / 10^7 ~= 2092278s ~= 581h



3) Nao sei como fazer isso ainda.

*/