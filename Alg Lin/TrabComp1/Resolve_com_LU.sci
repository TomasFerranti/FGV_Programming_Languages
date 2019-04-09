function [X]=Resolve_com_LU(C,P,B)
    [n]=size(C,1);
    [m]=size(B,2);
    L=eye(n,n);
    //Achar U usando C
    U=zeros(n,n);
    for i=1:n
        for j=i:n
            U(i,j)=C(i,j);
        end
    end
    //Achar L usando C e U
    L=L+(C-U);
    //X sera nossa matriz com as solucoes de cada sistema
    X=zeros(n,m);
    //Realizar cada sistema por vez:
    for i=1:m
        //b=i-esima coluna de B
        b=B(:,i);
        //Permutar B com as permutacoes realizadas na decomp LU de A
        b=P*b;
        //LUx=Pb
        //Ly=Pb
        //y=Ux
        //Declarando x e y ambos '0'
        y=zeros(n,1);
        x=y;
        //Adiciona uma nova coluna a L com o valor resultado do nosso sistema (b)
        L(:,n+1)=b;
        //Calcula y usando L e Pb
        y(1)=L(1,n+1)/L(1,1);
        for j=2:n
            y(j)=L(j,n+1)-L(j,1:j)*y(1:j);
        end
        U(:,n+1)=y;
        //Calcula x usando U e y
        x(n)=U(n,n+1)/U(n,n);
        for j=n-1:-1:1
            x(j)=(U(j,n+1)-U(j,j:n)*x(j:n))/U(j,j);
        end
        //Coloca x na sua respectiva posicao em X
        X(:,i)=x;
    end
endfunction
