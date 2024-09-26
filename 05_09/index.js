
		let arr = [0,1,0,2,1,0,1,3,2,1,2,1];
		let n = arr.length;
		let Lmax = 0, Rmax = 0, total = 0;
		let l = 0, r = n - 1;
	
		while (l <= r) {
			if (arr[l] <= arr[r]) {
				if (arr[l] >= Lmax) {
					Lmax = arr[l];
				} else {
					total += Lmax - arr[l];
				}
				l++;
			} else {
				if (arr[r] >= Rmax) {
					Rmax = arr[r];
				} else {
					total += Rmax - arr[r];
				}
				r--;
			}
		}
	
		console.log(total + " is the total traped water")
	