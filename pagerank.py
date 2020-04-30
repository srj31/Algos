
def pageRank(linkMatrix, d) :
	"""
		returns the rank of each website through power iteration and damping

		Input:
		linkMatrix : the probabilites of each website linked to a website
		d: damping factor

		Output:
		r : rank vector 
	"""
    n = linkMatrix.shape[0]
    M = d*linkMatrix + (1-d)/n*np.ones((n,n))
    r =100*np.ones(n)/n
    lastR = r
    r = M @ r
    while la.norm(lastR - r) > 0.01 :
        lastR = r
        r = M @ r
    return r