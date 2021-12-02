export default function contarOvejas(ovejas) {
    return ovejas.filter(o => o.color == 'rojo' && o.name.match(/a/i) && o.name.match(/n/i))
}