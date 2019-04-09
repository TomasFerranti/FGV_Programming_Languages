//////////////////////////////////////////////////////////////////////////
//Variáveis de saída:
//x: solução do sistema Ax=b (assumimos que tal solução existe).
//C: Seja A=LU a decomposição LU de A.
//Então C(i,j)=L(i,j) para i>j e C(i,j)=U(i,j) para j>=i.
//////////////////////////////////////////////////////////////////////////
function [x, C, P]=Gaussian_Elimination_3(A, b)
C=[A,b];
[n]=size(C,1);
P=eye(n,n);
for j=1:(n-1)
 //O pivô está na posição (j,j)
 if C(j,j)==0
  //Achando o indice tal que tenha o maior modulo abaixo do nosso pivo
  //PS: Esse codigo ocorre somente se o pivo for zero
  ind=find(abs(C(j+1:n,j))==max(abs(C(j+1:n,j))))(1)+j;
  //Troca de linhas na matriz escalonada
  C([j ind],:)=C([ind j],:);
  //Guardar as trocas na matriz de permutacao
  P([j ind],:)=P([ind j],:);
 end
 for i=(j+1):n
//O elemento C(i,j) é o elemento na posição (i,j) of L na decomposição LU de A
  C(i,j)=C(i,j)/C(j,j);
 //Linha i <- Linha i - C(i,j)*Linha j
//Somente os elementos acima da diagonal são computados (aqueles que
//compõem a matrix U)
  C(i,j+1:n+1)=C(i,j+1:n+1)-C(i,j)*C(j,j+1:n+1);
 end
end

x=zeros(n,1);
// Calcula x, sendo Ux=C(1:n,n+1)
x(n)=C(n,n+1)/C(n,n);
for i=n-1:-1:1
 x(i)=(C(i,n+1)-C(i,i:n)*x(i:n))/C(i,i);
end
C=C(1:n,1:n);
endfunction
