export default function createXmasTree(height) {
    const width = height * 2 - 1;
    let trunk = ''
    let tree = ''
    for (let i = 0; i < height; i++) {
        const n = i * 2 + 1
        const sides = '_'.repeat((width - n) / 2)
        const branches = '*'.repeat(i * 2 + 1)
        tree += sides + branches + sides + '\n'
        if (i === 0) { trunk = sides + '#' + sides; }
    }
    tree = tree + trunk + '\n'
    tree += trunk
    return tree
}