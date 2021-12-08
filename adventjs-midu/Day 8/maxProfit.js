export default function maxProfit(prices) {
    let max = 0
    for (let i = 0; i < prices.length; i++) {
        for (let j = i; j < prices.length; j++) {
            if (prices[j] - prices[i] > max) {
                max = prices[j] - prices[i]
            }
        }
    }
    return (max == 0) ? -1 : max
}