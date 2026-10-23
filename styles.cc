* {
    box-sizing: border-box;
}

body {
    margin: 0;
    padding: 20px 10px;
    background: linear-gradient(135deg, #e0eafc 0%, #cfdef3 100%);
    font-family: 'Hind Siliguri', 'Kalpurush', Arial, sans-serif;
    color: #333;
    min-height: 100vh;
}

.app-container {
    max-width: 900px;
    margin: 0 auto;
    background: #ffffff;
    border-radius: 16px;
    box-shadow: 0 10px 30px rgba(0,0,0,0.1);
    overflow: hidden;
}

.app-header {
    background: linear-gradient(135deg, #0d6efd, #0a58ca);
    color: #fff;
    text-align: center;
    padding: 30px 20px;
}

.app-header h1 {
    margin: 0 0 10px;
    font-size: 28px;
    font-weight: 700;
}

.app-header p {
    margin: 0;
    font-size: 15px;
    opacity: 0.9;
}

.main-content {
    padding: 25px;
}

.grid-row {
    display: grid;
    grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
    gap: 15px;
    margin-bottom: 20px;
}

.form-group {
    display: flex;
    flex-direction: column;
    margin-bottom: 15px;
}

.form-group label {
    font-weight: 600;
    margin-bottom: 6px;
    color: #2b3e50;
    font-size: 14px;
}

.form-control {
    padding: 10px 12px;
    border: 1px solid #cbd5e1;
    border-radius: 8px;
    font-size: 15px;
    outline: none;
    transition: all 0.2s;
}

.form-control:focus {
    border-color: #0d6efd;
    box-shadow: 0 0 0 3px rgba(13, 110, 253, 0.15);
}

.meter-box {
    background: #f1f5f9;
    padding: 15px;
    border-radius: 8px;
    margin-bottom: 20px;
}

.meter-title {
    font-weight: 600;
    margin-bottom: 10px;
    color: #475569;
    font-size: 14px;
}

.btn-calc {
    width: 100%;
    background: #0d6efd;
    color: white;
    border: none;
    padding: 14px;
    font-size: 16px;
    font-weight: 600;
    border-radius: 8px;
    cursor: pointer;
    transition: background 0.2s;
}

.btn-calc:hover {
    background: #0b5ed7;
}

.result-section {
    margin-top: 25px;
    background: #f8fafc;
    border-radius: 12px;
    padding: 20px;
    border: 1px solid #e2e8f0;
    display: none;
}

.result-section h3 {
    margin-top: 0;
    color: #1e293b;
    font-size: 18px;
}

.result-card {
    display: grid;
    grid-template-columns: repeat(auto-fit, minmax(200px, 1fr));
    gap: 15px;
    margin-bottom: 20px;
}

.res-item {
    background: #ffffff;
    padding: 12px 15px;
    border-radius: 8px;
    border-left: 4px solid #0d6efd;
    box-shadow: 0 2px 4px rgba(0,0,0,0.02);
}

.res-item.highlight {
    border-left-color: #198754;
    background: #f0fff4;
}

.res-item .label {
    font-size: 13px;
    color: #64748b;
}

.res-item .value {
    font-size: 18px;
    font-weight: 700;
    color: #1e293b;
    margin-top: 4px;
}

.late-fee-note {
    font-size: 14px;
    color: #dc2626;
    margin-bottom: 15px;
    font-weight: 500;
}

.breakdown-table {
    width: 100%;
    border-collapse: collapse;
    margin-top: 15px;
    background: #fff;
    border-radius: 8px;
    overflow: hidden;
}

.breakdown-table th, .breakdown-table td {
    padding: 10px 12px;
    text-align: left;
    border-bottom: 1px solid #f1f5f9;
    font-size: 14px;
}

.breakdown-table th {
    background: #e2e8f0;
    color: #334155;
}

.btn-print {
    background: #198754;
    color: white;
    border: none;
    padding: 10px 20px;
    font-size: 14px;
    font-weight: 600;
    border-radius: 6px;
    cursor: pointer;
    margin-top: 15px;
    display: inline-flex;
    align-items: center;
    gap: 8px;
}

.rules-card {
    margin-top: 30px;
    background: #fffbe3;
    border: 1px solid #ffe58f;
    border-radius: 12px;
    padding: 20px;
}

.rules-card h3 {
    margin-top: 0;
    color: #873800;
    font-size: 18px;
}

.rules-card ul {
    margin: 0;
    padding-left: 20px;
    font-size: 14px;
    line-height: 1.6;
    color: #595959;
}

.owner-footer {
    text-align: center;
    padding: 20px;
    background: #1e293b;
    color: #cbd5e1;
    font-size: 14px;
    margin-top: 30px;
}

.owner-footer strong {
    color: #38bdf8;
}

/* Modal Styling */
.modal-overlay {
    position: fixed;
    top: 0; left: 0; right: 0; bottom: 0;
    background: rgba(0,0,0,0.6);
    display: none;
    align-items: center;
    justify-content: center;
    z-index: 9999;
    padding: 15px;
}

.memo-box {
    background: white;
    width: 100%;
    max-width: 600px;
    border-radius: 12px;
    padding: 25px;
    max-height: 90vh;
    overflow-y: auto;
}

.memo-header {
    text-align: center;
    border-bottom: 2px solid #0d6efd;
    padding-bottom: 10px;
    margin-bottom: 15px;
}

.memo-header h2 {
    margin: 0;
    color: #0d6efd;
}

.memo-header p {
    margin: 5px 0 0;
    font-size: 13px;
    color: #64748b;
}

.memo-info {
    display: flex;
    justify-content: space-between;
    font-size: 13px;
    margin-bottom: 15px;
    background: #f8fafc;
    padding: 10px;
    border-radius: 6px;
}

.memo-calc-details {
    font-size: 14px;
    line-height: 1.8;
    margin-bottom: 15px;
}

.calc-row {
    display: flex;
    justify-content: space-between;
}

.calc-row.main-total {
    font-size: 16px;
    color: #198754;
}

.calc-row.late-total {
    font-size: 13px;
    color: #dc2626;
}

.memo-calc-details hr {
    border: none;
    border-top: 1px dashed #ccc;
    margin: 5px 0;
}

.memo-footer {
    text-align: center;
    border-top: 1px solid #e2e8f0;
    padding-top: 12px;
    margin-top: 20px;
    font-size: 12px;
    color: #64748b;
}

.memo-actions {
    text-align: right;
    margin-top: 20px;
}

.btn-print-action {
    background: #198754;
    color: #fff;
    border: none;
    padding: 8px 16px;
    border-radius: 5px;
    cursor: pointer;
}

.btn-close-action {
    background: #6c757d;
    color: #fff;
    border: none;
    padding: 8px 16px;
    border-radius: 5px;
    cursor: pointer;
    margin-left: 8px;
}

/* Print CSS */
@media print {
    body * {
        visibility: hidden;
    }
    #printableMemo, #printableMemo * {
        visibility: visible;
    }
    #printableMemo {
        position: absolute;
        left: 0;
        top: 0;
        width: 100%;
    }
    .no-print {
        display: none !important;
    }
}
