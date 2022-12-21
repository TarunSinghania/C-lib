int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}


int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

Notice that 𝑔𝑐𝑑(𝑥,𝑦,𝑧)=𝑔𝑐𝑑(𝑥,𝑔𝑐𝑑(𝑦,𝑧)). First we find 𝑎, 𝑏 such that 𝑔𝑐𝑑(𝑥,𝑔𝑐𝑑(𝑦,𝑧))=𝑎𝑥+𝑏𝑔𝑐𝑑(𝑦,𝑧), then 𝑐, 𝑑 such that 𝑔𝑐𝑑(𝑦,𝑧)=𝑐𝑦+𝑑𝑧. Finally we obtain 𝑔𝑐𝑑(𝑥,𝑦,𝑧)=𝑎𝑥+𝑏𝑐𝑦+𝑏𝑑𝑧. 