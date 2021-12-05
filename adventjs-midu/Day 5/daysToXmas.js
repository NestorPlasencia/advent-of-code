export default function daysToXmas(date) {
    const Xmas = new Date('Dec 25, 2021')
    return Math.ceil((Xmas - date) / (1000 * 60 * 60 * 24))
}