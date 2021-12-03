export default function isValid(letter) {
    let open = false
    let close = false
    let count = 0
    for (let i = 0; i < letter.length; i++) {
        const l = letter[i]
        if (open) {
            if (l === '(' || l === '[' || l === ']' || l === '{' || l === '}') {
                return false
            }
            if (l === ')' && count > 0) {
                open = false
                close = true
            }
            count++
        } else {
            if (l === '(') {
                open = true
                close = false
                count = 0
            }
        }
    }
    return close
}

export default function isValid(letter) {
    const gifts = letter.match(/\(.{1,}?\)/g)
    if(gifts){
        return gifts.map( g => (/\([^\(\)\[\]\{\}]{1,}\)/).test(g)).every( x => x)
    }else {
        return false
    }
}