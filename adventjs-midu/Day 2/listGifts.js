export default function listGifts(letter) {
    const arr = letter.split(' ').filter(g => !g.includes('_') && (g != ''))
    const obj = {}
    arr.forEach(g => { (!obj.hasOwnProperty(g)) ? obj[g] = 1 : obj[g] += 1 })
    return obj
}