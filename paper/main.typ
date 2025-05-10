#import "@preview/unify:0.7.0": num,qty,numrange,qtyrange
#import "@preview/codly:1.3.0": *
#import "@preview/codly-languages:0.1.1": *

#import "macros.typ": taula-veritat 

#show: codly-init.with()

#codly(languages: codly-languages, zebra-fill: luma(250), display-icon: false)

#set text(
  12pt,
  font: "New Computer Modern",
  lang: "ca"
)

#show link: it => {
  if type(it.dest) == label {
    it
  } else {
    underline(it)
  }
}

#show ref: it => context {
  if it.element.has("level") and it.element.level == 1 {
    link(it.target)[Part #counter(heading).at(it.target).first()]
  } else {
    it
  }
}

#page[
  #align(center)[
    #text(20pt, weight: "bold")[Calculadora digital amb Arduino]
    
    #text(16pt, weight: "bold")[Programació i electrònica]
    


    #text(16pt, weight: "bold")[Àlex Xavier Touza Luque]

    #text(14pt)[
      2n Batxillerat B --- Curs 2024-2025 \
      _Tecnologia i Enginyeria II_ \
      Millora de nota 3r trimestre
    ]
  ]
]

#set page(header: [Àlex Xavier Touza Luque #h(1fr) Tecnologia i Enginyeria II], numbering: "1")

#set par(spacing: 1.5em, first-line-indent: 2em, leading: 1em, justify: true, linebreaks: "optimized")


#show outline: set par(leading: 1em)





#show outline.entry.where(level: 1): smallcaps
#show outline.entry.where(level: 1): text.with(weight: "bold")

#show outline.entry.where(
  level: 1
): set block(above: 2.5em)

#outline(title: "Taula de continguts", indent: 2em)

#pagebreak(weak: true)


#show heading.where(level: 1): set heading(supplement: none)

#show heading.where(level: 4): it => {  
  set text(12pt, style: "italic", weight: "regular")
  
  it
}



#let cpp = raw.with(lang: "cpp")

#show heading.where(level: 1): it => {
  set text(32pt)
  set par(justify: false, leading: 0.7em)

  pagebreak(weak: true)
  v(10%)
  
  it
}

= Introducció

El propòsit d'aquest treball ha estat dissenyar, muntar i programar una calculadora digital mitjançant un circuit electrònic en una placa de prototipatge i la plataforma Arduino.

El projecte inicialment consistia en, únicament, un programa que mostrés un nombre en una pantalla de set segments, segons l'entrada d'un conjunt de botons, imitant la pantalla d'una calculadora. Tanmateix, la metodologia d'aquesta tasca ---ús de C++ i PlatformIO--- va permetre realitzar-la de forma satisfactòria i ràpida, cosa que va motivar ampliar-la a un projecte de creació d'una calculadora.

El projecte, dut a terme durant les vacances de primavera, ha tingut un resultat notable, motiu pel qual l'autor ha desitjat redactar aquest informe per deixar-lo en constància, indepndentment de la seva incidència en qualificacions acadèmiques.

En un intent de relacionar aquest treball amb els continguts de l'assignatura, es fa menció a molts conceptes treballats a classe, tals com els components dels sistemes de control i les funcions lògiques.

Aquest document s'estructura en tres parts: a la primera, s'exposa, de manera senzilla i esquemàtica, les funcionalitats del dispositiu que s'ha dissenyat, mostrades també per un curt vídeo que s'enllaça en aquesta mateixa secció. A la segona part, s'ennumeren els components electrònics utilitzats en el muntatge físic, des dels conductors fins als receptors i actuadors, així com la seva interconnexió. A la tercera i última part, s'explica en detall l'aspecte informàtic del projecte, exposant la metodologia i el disseny de la programació, així com en què consisteixen alguns algorismes i funcions lògiques utilitzades.


#set heading(numbering: (..n) => {
  if (n.pos().len() == 1) {
    [Part #str(n.pos().first()).]
  } else if (n.pos().len() == 4) {
    return h(-0.3em)
  } else {
    return numbering("1.", ..n)
  }
})

#show heading.where(level: 1): it => {
  set text(32pt)
  set par(justify: false)

  pagebreak(weak: true)
  v(30%)
  
  it
}

= Funcionament

= Electrònica i sistema de control

== Components

=== Unitat de control

=== Elements de comandament

Els únics elements de comandament de la calculadora ---la interfície de l'usuari--- són botons. #datetime.today().display("[month repr:long]")

Els botons estan col·locats en dues plaques de proves (_breadboards_) i cadascun coincideix en un polsador petit bàsic i una tapa de colors diversos que ajuda a identificar les funcions. Per assolir aquest mateix fi, s'hi han enganxat etiquetes ---força rudimentàries, certament--- que indiquen l'acció associada a cada botó.

En total, hi ha 19 botons i es classifiquen segons la @tab:botons_tipus.

#figure(table(
  columns: 2,
  stroke: none,
  align: (x, y) => {
    if x == 1 {
      return right
    } else {
      return auto
    }
  },
  table.header[*Tipus de botó*][*Quantitat*],
  table.hline(),
  [Acció], [4],
  [Operació], [5],
  [Nombres], [10],
),
caption: [Tipus i quantitat de botons.]) <tab:botons_tipus>

A més, dos dels botons d'operacions ---producte i quocient--- tenen una funció secundària ---potència i mòdul, respectivament--- que s'activa prement el botó dues vegades.

Tal com s'exposa a la @chap:programacio,

=== Visualitzadors de dades

Com és lògic, l'únic visualitzador de dades d'una calculadora senzilla és la seva pantalla. La calculadora d'aquest projecte està formada per cinc pantalles de set segments, un per cada dígit. Tanmateix, el codi està fet per adaptar-se a qualsevol nombre de dígits raonable ---tres com a mínim---, de manera que se'n poden afegir més si cal.

=== Elements auxiliars

Els elements auxiliars del circuit són les plaques de proves i els cables. S'han utilitzat tres plaques de proves ---dues de grans i una de petita---.

Les limitacions  temporals, artístiques i de recursos de l'autor del projecte l'han forçat a no tenir el disseny d'algun tipus de caixa dedicada i, en lloc, mantenir els components sobre les plaques de proves.

== Connexió

=== Pantalles de set segments

===


= Lògica i programació <chap:programacio>

== Metodologia

== Enfocament

=== Paradigma

El programa està basat en el paradigma de la programació orientada a objectes (OOP, de l'anglès _object oriented programming_).

S'ha preferit aquesta filosofia per sobre de la comuna en els programes d'Arduino ---que sovint consisteixen en un llarg codi amb organització escassa i un nombre considerable de variables--- perquè una estructura clara i prèviament meditada permet que el codi sigui, per una banda, més llegible i agradable per al programador i altres que mirin el codi, i per l'altra, més fàcil d'afegir-hi noves funcionalitats.

=== Tècniques de programació

Degut a les limitacions de l'entorn d'Arduino, la llibreria estàndard de C++ ---les funcions integrades en els compiladors del llenguatge, que són, de fet, una de les característiques més apreciades d'aquest--- no està disponible. Per aquest motiu, hom ha de recórrer a 

=== Conceptes importants

Aquí es definiran una sèrie de conceptes importants relacionats amb l'enfocament de la programació del projecte.

==== Punter

Un punter és una adreça de memòria que _apunta_ a una altra variable. Al C++, els punters s'indiquen amb un asterisc, de manera que #cpp("int*") expressa un punter a un enter.

==== Objecte

Un objecte és una col·lecció de variables ---que defineixen el seu estat actual--- i mètodes ---que permeten alterar el seu estat---. És preferible fer servir objectes en lloc de variables i funcions soltes per millorar l'organització del codi.

Els objectes permeten obtenir codi més expressiu. Per exemple, en lloc d'escriure #raw(lang: "cpp", "digitalWrite(led, HIGH)"), hom escriuria #raw(lang: "cpp", "led->on()"). El codi de més baix nivell queda abstret dins del mètode `on()`, de manera que en fer servir l'objecte hom no s'ha de preocupar per la seva implementació.

==== Classe

Una classe és una plantilla per crear objectes. La majoria de llenguatges orientats a objectes, com C++, no permet crear objectes a voluntat, sinó que s'han de _construir_ a partir de classes.

==== Abstracció

==== Encapsulació

==== Herència

==== Polimorfisme







//En aquest capítol, es descriurà l'estructura pública del programa; és a dir, tot el que ha de saber una persona que vol fer servir el programa per al seu ús previst (i.e. )

== Estructura <estructura>




== Càlcul i memòria

Si bé podria semblar el contrari, el funcionament de les calculadores senzilles és ben sofisticat; s'han d'adaptar als diferents usos i possibilitats que tenen, així que existeixen moltes seqüències de tecles possibles. Les múltiples proves que s'han realitzat amb calculadores reals, a partir de les quals s'ha anotat el seu funcionament, ha revelat la lògica interna d'aquests dispositius.

L'objectiu final no és pas replicar cada seqüència una per una, sinó trobar una lògica més simple que permeti executar totes aquestes seqüències.

=== Exemples de seqüències de funcionament

Farem servir la següent notació:

$
N := "introduir un nombre" \ O := "prémer la tecla d'una operació" \ "C" := "calcular" \ (A) :="acció opcional; es pot ometre sense alterar el funcionament" \ [A, B, C,...]_(i=1)^n := "repetició de les operacions" A,B,C... space n "vegades amb" \ "el comptador" i "començant en" 1
$

1. *Aplicació d'una operació binària.* Si fem una operació inicial $"Op"()$Mantenim $N_1$ en la memòria i apliquem l'operació amb $N_2$ en prémer la tecla de l'igual.

  $ N_1,O,N_2,C $

2. *Encadenament d'operacions binàries.* Aquí observem que prémer la tecla d'una operació també executa el càlcul.

  $ N_1,O_1,N_2, [(C), O_i, N_(i+1)]_(i=2)^n $

3. *Aplicació repetida d'una operació binària.* Si fem una operació inicial $"Op"(N_1, N_2)$ i premem repetidament la tecla de calcular, aleshores es calcula l'operació $"Op"(r, N_2)$, on $r$ és el resultat de l'operació anterior.
  
  $
  N_1, O, N_2, [C]^n
  $



== Algorísmia i lògica

En aquest apartat, s'exposaran alguns dels algorismes i procediments lògics que s'han fet servir al codi de la Calculadora, a més de com s'executen els càlculs, que ja ha estat discutit a la secció anterior.

=== Processament de senyals d'entrada

Els únics components d'entrada de la Calculadora són, tal com s'ha exposat a la @estructura, els botons. S'ha dedicat especial atenció al processament dels senyals d'entrada per tal d'assegurar una interacció de l'usuari satisfactòria. Amb aquesta finalitat, els botons només executen l'acció corresponent quan es deixen de prémer. Aquesta funcionalitat requereix un algorisme simple però meditat.

L'algorisme és equivalent a un circuit digital aritmètic seqüencial amb la següent taula de veritat. En electrònica, aquesta tècnica és coneguda amb el nom _falling edge_.

#figure({
  set align(left)
  set par(leading: 0.75em)
  taula-veritat(
    2,
    (
      (0,0,1,1),
      (0,1,0,0),
    ),
    (
      [No s'està prement el botó ni s'estava prement el botó abans, així que ni es dona el senyal d'entrada ni s'activa la memòria.],
      [
        S'estava prement el botó abans, però s'ha deixat de prèmer. Aleshores, es desactiva la memòria i es dona el senyal d'entrada.
      ],
      [
        No s'estava prement el botó abans, però s'ha començat a prèmer. S'activa la memòria però encara no es dona el senyal d'entrada.
      ],
      [
        S'estava prement el botó i es continua prement, així que es manté la memòria però encara no es dona el senyal d'entrada.
      ]
    ),
    letters: ([$B$], [$M$], [$M'$], [$E$]),
    ordered: false,
  )
}, caption: [Taula de veritat del sistema lògic de l'entrada de senyal dels botons.

$B$ indica si es prem el botó o no, $M$ és la memòria i $E$ és el senyal d'entrada final, el que executa l'acció.])

Les funcions lògiques corresponents són:

$
M' = B \ E = overline(B) dot M
$

A continuació, es mostra el fragment de codi corresponent a aquest procediment. El booleà `_value` és $B$, `this->value` és $E$ i `this->active` és $M$.

```cpp
unsigned int Pins::DigitalIn::read() {
    unsigned int _value = digitalRead(this->pin);
    if (this->invert) _value = !_value;

    if (this->debounce) {
        if (_value) {
            _value = 0;
            this->active = true;
        } else if (this->active) {
            _value = 1;
            this->active = false;
        }
    }
    
    return this->value = _value;
}
```

Comprovar que, efectivament, la lògica d'aquest codi és equivalent a les funcions lògiques anteriors es proposa com a exercici per al lector.