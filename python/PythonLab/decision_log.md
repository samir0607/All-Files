# Data Processing Decision Log

**Dataset:** Titanic
**Processing Date:** 2025-08-11 07:52:29
**Original Shape:** (891, 15)
**Final Shape:** (891, 20)

## Processing Decisions

### 1. Age - Imputed

- **Method:** median by class and sex
- **Affected Records:** 177
- **Rationale:** Age varies significantly by class and sex, median imputation by group preserves relationships

### 2. Embarked - Imputed

- **Method:** mode
- **Affected Records:** 2
- **Rationale:** Mode imputation for categorical variable with few missing values

### 3. Deck - Imputed

- **Method:** mode or Unknown
- **Affected Records:** 688
- **Rationale:** Categorical variable imputation

### 4. Embark_Town - Imputed

- **Method:** mode or Unknown
- **Affected Records:** 2
- **Rationale:** Categorical variable imputation

### 5. Fare - Outlier Treatment

- **Method:** winsorization at 5th and 95th percentiles
- **Affected Records:** 116
- **Rationale:** Winsorization preserves data points while reducing extreme value impact. Suitable for fare data where high values might be legitimate first-class tickets.

## Summary of Changes

- Total missing values handled: 869
- Flag columns created: 5
- Outlier treatment applied: Yes
