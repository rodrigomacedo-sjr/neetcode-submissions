func isAnagram(s string, t string) bool {
	var a [26]int
	var b [26]int

	for _, c := range s {
		a[c - 'a']++
	}

	for _, c := range t {
		b[c - 'a']++
	}

	return a == b
}
