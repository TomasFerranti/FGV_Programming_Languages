function [lambda,x,N] = Metodo_Potencia_Simetrica(A,x0,epsilon,M)
    x=x0/norm(x0,2)
    for N=1:M
        y=A*x
        lambda=x'*y
        if norm(y,2)==0
            disp("A tem autovalor 0, selecione um novo vetor inicial x e recomece")
        end
        ERR=norm(x-y/norm(y,2),2)
        x=y/norm(y,2)
        if ERR<epsilon
            disp("Autovalor e autovetor encontrados!")
            x=x(:,1)
            return
        end
    end
    x=x(:,1)
    disp("O valor máximo de iterações foi alcançado. Não obtivemos sucesso.")
endfunction
