function reverseArray(a, i){
	var first = i;
	var second = a.length - i - 1;
	if(second > first){
		var t = a[first];
		a[first] = a[second];
		a[second] = t;
		return reverseArray(a, i + 1);
	}
	else return;
}
var a = [1, 2, 3, 4, 5];
var b = [5, 2, 3, 42, 1];
reverseArray(a, 0);
reverseArray(b, 1);
console.log(a);
console.log(b);