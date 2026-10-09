class Solution {
    /**
     * @param {string} s
     * @param {string} t
     * @return {boolean}
     */
    isAnagram(s: string, t: string): boolean {
		let a = s.split('');
		let b = t.split('');
		return a.sort().join() == b.sort().join();
	}
}
