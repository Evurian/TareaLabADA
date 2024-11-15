#include <iostream>
#include <cstring>
#include <numeric>
using namespace std;

int M, sum, sticks[20];
int memo[1 << 20];

bool canFormSquare(int length, int bitMask)
{
    if (memo[bitMask] != -1)
        return memo[bitMask];
    
    // Si el largo actual excede el tamaño del lado, no es una solución válida
    if (length > sum / 4)
        return memo[bitMask] = 0;
    
    // Si logramos un lado, reiniciamos el largo y seguimos buscando los otros lados
    if (length == sum / 4)
    {
        // Si hemos usado todos los palos, formamos un cuadrado
        if (bitMask == (1 << M) - 1)
            return memo[bitMask] = 1;
        
        // Reiniciamos el largo para formar el siguiente lado
        length = 0;
    }

    // Intentamos agregar palos restantes al lado actual
    for (int i = 0; i < M; ++i)
        if (!(bitMask & (1 << i)) && canFormSquare(length + sticks[i], bitMask | (1 << i)))
            return memo[bitMask] = 1;
    
    // Si no se encuentra solución, almacenamos y devolvemos 0
    return memo[bitMask] = 0;
}

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        cin >> M;
        for (int i = 0; i < M; ++i)
            cin >> sticks[i];
        
        sum = accumulate(sticks, sticks + M, 0);
        if (sum % 4 != 0)
            cout << "no" << endl;
        else
        {
            memset(memo, -1, sizeof memo);
            cout << (canFormSquare(0, 0) ? "yes" : "no") << endl;
        }
    }
    return 0;
}
