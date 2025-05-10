#let taula-veritat(n, out,  expl, order: none, letters: ("a", "b", "c", "d", "e"), ordered: true) = {
  let outs = out.len()

  let nulls = out.first().enumerate().filter(((i, x)) => x == none).map(((i, x)) => i)

  let w = n + outs + 1 + int(ordered)
  
  let arr = ()
  let l = calc.pow(2,n)

  for i in range(n) {
    let col = ()


    for j in range(l) {
      
      
      col.push(calc.rem(calc.floor(j / calc.pow(2, i)), 2))
    }

    arr.insert(0, col)

    
  }

  show table.cell.where(y: 0): strong


  let if-ordered(x) = {
    if type(x) == function {
      if ordered {(x(),)} else {()}
    } else {
      if ordered {(x,)} else {()}
    }
  }

  let format(x) = {
    if x == none {
      return table.cell(fill: red.transparentize(60%), align: center, sym.crossmark)
    } else if x == 1 {
      return table.cell(fill: green.transparentize(50%), [#x])
    } else if x == 0 {
      return table.cell(fill: orange.transparentize(40%), [#x])
    } else {
      return x
    }
  }

  let fill(arr) = {
    while arr.len() < l {
      arr.push([])
    }
    return arr
  }

  expl = fill(expl)

  if ordered {
    order = fill(order)
  }

  for (i, a) in out.enumerate() {
    out.at(i) = fill(a)
  }
  
  table(
    align: (x, y) => {
      if (x <= (n + outs - 1) or (x == w - 1 and ordered)) and y > 0 {
        return center + horizon
      } else {
        return horizon
      }
    },
    
    columns: (..range(n + outs).map(_ => (30pt)), 1fr, ..if-ordered(60pt)),
    //columns: n + outs + 1 + int(ordered),
    fill: (x, y) => {
      if y == 0 {
        return blue.transparentize(75%)
      } else if (y - 1) in nulls {
        return red.transparentize(90%)
      }
    },
    table.header(..letters.slice(0, n + outs), [Explicació], ..if-ordered([Ordre])), 
    ..((array.zip(
      ..arr,
      ..out.map(row => row.map(format)),
      expl.map(text.with(10pt)),
      ..if-ordered( () => order.map(format))
    )).flatten().map(n => [#n])),
    table.vline(position: start, x: n, start: 0, end: l+2, stroke: 2pt),
    table.vline(position: start, x: n + outs, start: 0, end: l+2, stroke: 2pt)
  )
}

