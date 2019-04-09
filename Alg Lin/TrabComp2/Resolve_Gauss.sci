function [xi2,Nd,k,nR] = Resolve_Gauss(A,b,x0,E,M,tN)
    D=diag(diag(A))
    L=tril(A,-1)
    U=A-D-L
    invL_mais_D=inv(L+D)
    Mg=-invL_mais_D*U
    Cg=invL_mais_D*b
    xi1=x0
    nR=norm(b-xi1,tN)
    for k=1:M
        xi2=Mg*xi1+Cg
        Nd=norm(xi2-xi1,tN)
        if Nd<E then
            disp('Tolerância alcançada.')
            return
        end
        xi1=xi2  
        nR=norm(b-xi1,tN)      
    end
    disp('Número de Iterações Máximo Alcançado')
endfunction
