# Pi C++ 

Programma in C++ che trova una approssimazione del valore di π prendendo punti a caso su un quadrato di lato 1.

Permette di eseguire l'algoritmo più volte e di mostrare la media aritmetica totale.

---

### Istruzioni

All'esecuzione del programma:
- immettendo un numero *n* troverà una stima del valore di π *n* volte;
- immettendo **m** stamperà a schermo la media di tutte le stime eseguite finora;
- con **q** si esce dal programma.

---

### Spiegazione del metodo

Trova il valore di π prendendo punti a caso su un quadrato di
lato 1 e controllando se il punto è all'interno del quarto di una circonferenza
di raggio 1 usando l'equazione della circonferenza 

>$x^2 + y^2 = 1$.

Se $x^2 + y^2 \le 1$ il punto è all'interno della circonferenza.

Per ottenere il valore stimato di π divide il numero di punti interni al cerchio
con il numero totale di punti presi a caso, infine moltiplicando il risultato per 4.

Risoluzione ottenuta da:

>Dove Aq è l'area del quadrato e Ac l'area di un quarto di cerchio.
>$Aq = l^2 \Rightarrow Aq = r^2$\
\
>$\begin{cases}
Aq = r^2\\
Ac = \dfrac{πr^2} {4}
\end{cases}$
\
\
>$Ac =$ $ \dfrac {πAq} {4} \Rightarrow π=\dfrac {Ac} {Aq} \cdot 4 $

Nel rapporto $\dfrac{Ac} {Aq} \cdot 4$ i punti presi a caso interni al cerchio possono essere considerati Ac e i punti presi in totale Aq perché, per quanto il numero dei puntini non rappresenti l'area delle figure, il rapporto tra punti interni e punti totali è all'incirca uguale al rapporto tra area del cerchio e area del quadrato.