//За програмски јазик да се употреби C.


//Од стандарден влез се внесува број n, број на кругови кои ќе се внесуваат, каде 0<n<100. Потоа во наредните n линии се внесуваат x и y кои го претставуваат центарот на кругот како и радиусот на кругот. На стандарден излез се печати плоштината и центарот само најголемиот круг (со најголема плоштина).



//Напомена: Доколку има повеќе кругови со иста плоштина се печати само првиот круг со таа плоштина.



//Во структурата Точка (Point) треба да се чуваат следните информации:

//-x координата (int)

//-y координата (int)



//Во структурата Круг (Circle) треба да се чуваат следните информации:

//-Центар (Point)

//-Радиус (int)


#include <stdio.h>
//pravime struktura sto ke cuva informacii za koordinatite na krugot
typedef struct Tocka 
{
    int x;
    int y;
}tocka;
//pravime struktura sto ke cuva informacii za radiusot na soodvetniot krug, i negovite koordinati
typedef struct Krug 
{
    tocka t;
    float radius;
}krug;
int main()
{
    float PI = 3.14;//definirame promenliva PI za potrebnite formuli(baranje na plostina)
    int n;
    scanf("%d",&n);//skenirame vrednost za N krugovi
    float najgolemaPlostina = 0;//kreirame promenliva najgolemaPlostina sto ke ja cuva najgolemata presmetana plostina vo zadacata
    krug najgolem = {{0,0},0};//kreirame krug so X=0,Y=0 i radius=0 sto ke ni sluzi za presmetki vo ciklusot dolu

    for (int i = 0; i < n; i++) {
         krug k;//kreirame krug i dolu mu dodeluvame vrednosti za koordinati i radius
        scanf("%d%d%f", &k.t.x,&k.t.y,&k.radius);
        float plostina = k.radius * k.radius * PI;//presmetuvame plostina na kreiraniot krug vo ciklusot
        if (plostina > najgolemaPlostina) {//ako plostinata na segasniot krug e pogolema od najgolemata plostina sto sme ja nasle prethodno(inicijalno 0 ja postavuvame)
            najgolem = k;//na najgolemiot krug mu gi dodeluvame vrednostite od krugot sto sme go nasle vo presmetkite
            najgolemaPlostina = plostina;//i plostinata sto sme ja nasle vo ciklusot ja memorirame vo nasata promenliva najgolemaPlostina
        }
    }
    printf("Largest circle has area of: %.2f with centre: (%d,%d)",najgolemaPlostina,najgolem.t.x,najgolem.t.y);//ja pecatime plostinata od najgolemiot krug, i negovite koordinati
}



