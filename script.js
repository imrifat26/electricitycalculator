// Residential Slab Tariffs (LT-A)
const residentialSlabs = [
    { max: 50, rate: 4.63, label: '০ - ৫০ ইউনিট (লাইফলাইন)' },
    { max: 75, rate: 5.26, label: '০ - ৭৫ ইউনিট' },
    { max: 200, rate: 7.20, label: '৭৬ - ২০০ ইউনিট' },
    { max: 300, rate: 7.59, label: '২০১ - ৩০০ ইউনিট' },
    { max: 400, rate: 8.02, label: '৩০১ - ৪০০ ইউনিট' },
    { max: 600, rate: 12.67, label: '৪০১ - ৬০০ ইউনিট' },
    { max: Infinity, rate: 14.61, label: '৬০০ ইউনিটের উপরে' }
];

let globalCalcData = {};

function calcUnitsFromReading() {
    const prev = parseFloat(document.getElementById('prevReading').value) || 0;
    const curr = parseFloat(document.getElementById('currReading').value) || 0;
    if (curr >= prev && curr > 0) {
        document.getElementById('units').value = curr - prev;
    }
}

function calculateBill() {
    const unitsInput = parseFloat(document.getElementById('units').value);
    if (isNaN(unitsInput) || unitsInput < 0) {
        alert('অনুগ্রহ করে সঠিক ইউনিট ইনপুট দিন।');
        return;
    }

    const category = document.getElementById('category').value;
    const provider = document.getElementById('provider').value;

    let energyCharge = 0;
    let breakdown = [];

    if (category === 'LTA') {
        if (unitsInput <= 50) {
            energyCharge = unitsInput * 4.63;
            breakdown.push({ label: '০ - ৫০ ইউনিট (লাইফলাইন)', units: unitsInput, rate: 4.63, cost: energyCharge });
        } else {
            let prevMax = 0;
            for (let i = 1; i < residentialSlabs.length; i++) {
                let slab = residentialSlabs[i];
                let slabCap = slab.max - prevMax;
                
                if (unitsInput > prevMax) {
                    let currentUnitsInSlab = Math.min(unitsInput - prevMax, slabCap);
                    let cost = currentUnitsInSlab * slab.rate;
                    energyCharge += cost;
                    breakdown.push({ label: slab.label, units: currentUnitsInSlab, rate: slab.rate, cost: cost });
                    prevMax = slab.max;
                } else {
                    break;
                }
            }
        }
    } else {
        let flatRate = 6.00;
        if (category === 'AGRICULTURE') flatRate = 4.82;
        if (category === 'SMALL_IND') flatRate = 9.88;
        if (category === 'COMMERCIAL') flatRate = 12.25;

        energyCharge = unitsInput * flatRate;
        breakdown.push({ label: 'ফ্ল্যাট রেট', units: unitsInput, rate: flatRate, cost: energyCharge });
    }

    const demandCharge = 42.00;
    const meterRent = 40.00;
    const fixedCharges = demandCharge + meterRent;
    const vat = (energyCharge + fixedCharges) * 0.05;
    const totalBill = energyCharge + fixedCharges + vat;
    const lateTotalBill = totalBill * 1.05;

    // Update UI
    document.getElementById('resEnergy').innerText = '৳ ' + energyCharge.toFixed(2);
    document.getElementById('resFixed').innerText = '৳ ' + fixedCharges.toFixed(2);
    document.getElementById('resVat').innerText = '৳ ' + vat.toFixed(2);
    document.getElementById('resTotal').innerText = '৳ ' + totalBill.toFixed(2);
    document.getElementById('resLateTotal').innerText = '৳ ' + lateTotalBill.toFixed(2);

    let tbody = document.getElementById('slabTableBody');
    tbody.innerHTML = '';
    breakdown.forEach(row => {
        tbody.innerHTML += `<tr>
            <td>${row.label}</td>
            <td>${row.units}</td>
            <td>৳ ${row.rate}</td>
            <td>৳ ${row.cost.toFixed(2)}</td>
        </tr>`;
    });

    document.getElementById('resultSection').style.display = 'block';

    // Save global data for memo
    globalCalcData = {
        provider, category, units: unitsInput, energyCharge, fixedCharges, vat, totalBill, lateTotalBill, breakdown
    };
}

function openMemoModal() {
    document.getElementById('mProvider').innerText = document.getElementById('provider').options[document.getElementById('provider').selectedIndex].text;
    document.getElementById('mCategory').innerText = document.getElementById('category').options[document.getElementById('category').selectedIndex].text;
    document.getElementById('mUnits').innerText = globalCalcData.units;
    document.getElementById('mDate').innerText = new Date().toLocaleDateString('bn-BD');

    let mBody = document.getElementById('mSlabBody');
    mBody.innerHTML = '';
    globalCalcData.breakdown.forEach(row => {
        mBody.innerHTML += `<tr>
            <td>${row.label}</td>
            <td>${row.units}</td>
            <td>৳ ${row.rate}</td>
            <td>৳ ${row.cost.toFixed(2)}</td>
        </tr>`;
    });

    document.getElementById('mEnergy').innerText = '৳ ' + globalCalcData.energyCharge.toFixed(2);
    document.getElementById('mFixed').innerText = '৳ ' + globalCalcData.fixedCharges.toFixed(2);
    document.getElementById('mVat').innerText = '৳ ' + globalCalcData.vat.toFixed(2);
    document.getElementById('mTotal').innerText = '৳ ' + globalCalcData.totalBill.toFixed(2);
    document.getElementById('mLateTotal').innerText = '৳ ' + globalCalcData.lateTotalBill.toFixed(2);

    document.getElementById('memoModal').style.display = 'flex';
}

function closeMemoModal() {
    document.getElementById('memoModal').style.display = 'none';
}
