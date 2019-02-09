/*
Warnings:
- C++ IO used. FASTIO needed
- matrix can only hold integers.
- Assertions NOT IMPLEMENTED PROPERLY
- Size is given as pair <row, column>. When matrix is N*N, size can be checked with A.getsize().first .
- Matrix is maintained as array (static memory)

Implemented Functions
- Matrix operator +, -, *, = (assign)
- Matrix power and power-modulo
- Matrix modulo constant
- Matrix transpose

Need to Add...
- Matrix Inverse
- Determinant
- LU decomposition
- Eigenvalues and Eigenvectors
- Strassen's fast Matrix multiplication

*/


#define ll long long
#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define MP make_pair
#define PB push_back
using namespace std;


typedef pair<int,int> pii;

class matrix
{
private:
    int col;
    int row;
    int **p;
    void allocArray()
    {
        p = new int*[row];
        for(int i = 0; i < row; i++)
            p[i] = new int[col];
    }

public:
    matrix();
    matrix(int r, int c);
    void printmatrix();
    void setvalue(int r, int c, int val);
    pii getsize();
    int getvalue(int r, int c);
    matrix operator+(const matrix &A);
    matrix operator-(const matrix &A);
    matrix operator*(const matrix &A);
    matrix operator%(const int modulo);
    void operator=(const matrix &A);
    matrix transpose();
    ~matrix();

};

pii matrix::getsize()
{
    int r = row, c = col;
    pair <int, int> sizepair = {r,c};
    return sizepair;
}

matrix::~matrix()
{
    for(int i = 0; i < row; i++)
        delete [] p[i];
    delete [] p;
}

matrix::matrix()
{
    cin >> row >> col;
    allocArray();
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            p[i][j] = 0;
}

matrix::matrix(int r, int c)
{
    row = r, col = c;
    allocArray();
}

int matrix::getvalue(int r, int c)
{
    return p[r][c];
}

void matrix::setvalue(int r, int c, int val)
{
    p[r][c] = val;
    return;
}

void matrix::printmatrix()
{
    int r = row, c = col;
    for(int i = 0; i<r; i++)
    {
        for (int j = 0; j<c; j++)
        {
            cout << p[i][j] << " ";
        }
        cout << "\n";
    }
}

matrix matrix::transpose()
{
    matrix tmp(col,row);
    for (int i = 0; i<row; i++)
        for (int j = 0; j<col; j++)
            tmp.p[j][i] = p[i][j];
    return tmp;
}

void matrix::operator=(const matrix &A)
{
    if (p!=A.p && col == A.col && row == A.row)
    {
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                p[i][j] = A.p[i][j];
    }
}

matrix matrix::operator+(const matrix &A)
{
    matrix tmp(row,col);
    if (col == A.col && row == A.row)
    {
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                tmp.p[i][j] = p[i][j]+A.p[i][j];
    }
    return tmp;
}

matrix matrix::operator-(const matrix &A)
{
    matrix tmp(row,col);
    if (col == A.col && row == A.row)
    {
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                tmp.p[i][j] = p[i][j]-A.p[i][j];
    }
    return tmp;
}

matrix matrix::operator*(const matrix &A)
{
    matrix tmp(row,A.col);
    if (col == A.row)
    {
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < A.col; j++)
            {
                int mul=0;
                for (int k = 0; k<col; k++)
                {
                    mul += p[i][k]*A.p[k][j];
                }
                tmp.p[i][j] = mul%mod;
            }
        }

    }
    return tmp;
}

matrix matrix::operator%(const int modulo)
{
    matrix tmp(row,col);
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            tmp.p[i][j] = (p[i][j] % modulo);
    return tmp;
}

matrix identity(int n)
{
    matrix id(n,n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            id.setvalue(i,j, (i==j? 1 : 0));
    return id;
}

matrix zeromatrix(int n)
{
    matrix zero(n,n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            zero.setvalue(i,j,0);
    return zero;
}

matrix pow(matrix &A, long long exp)
{
    if (exp==0)
        return (identity((A.getsize()).first));
    if (exp&1)
    {
        return (pow(A, exp-1) * A);
    }
    else
    {
        matrix half = pow(A, exp/2);
        return (half * half);
    }
}

matrix powmod(matrix &A, long long exp, long long modulo)
{
    if (exp==0)
        return (identity((A.getsize()).first));
    if (exp&1)
    {
        return (powmod(A, exp-1, modulo)%modulo * A%modulo)%modulo;
    }
    else
    {
        matrix half = powmod(A, exp/2, modulo)%modulo;
        return (half * half)%modulo;
    }
}

void setmatrix(matrix &A, int r, int c)
{
    int v;
    for (int i = 0; i<r; i++)
    {
        for (int j = 0; j<c; j++)
        {
            cin >> v;
            A.setvalue(i,j,v);
        }
    }
}

int main()
{

}
